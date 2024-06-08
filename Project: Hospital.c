#include <stdio.h> 

#include <stdlib.h> 

#include <string.h> 

  

typedef struct { 

    char cpf[15]; 

    char nome[50]; 

    int sexo; // 1 para feminino, 2 para masculino 

    char email[50]; 

    char data_nascimento[11]; 

    char telefone[15]; 

    char cpf_terceiro[15]; 

    char nome_terceiro[50]; 

    char data_nascimento_terceiro[11]; 

    float valor_plano; 

    char data_vencimento_plano[11]; 

    int tipo_plano; // 1 - Ouro, 2 - Diamante, 3 - Prata, 4 - Esmeralda 

    int num_dependentes; 

} Cliente; 

  

float calcular_valor_plano(Cliente cliente) { 

    float valor_base; 

    switch (cliente.tipo_plano) { 

        case 1: valor_base = 300.00; break; 

        case 2: valor_base = 400.00; break; 

        case 3: valor_base = 200.00; break; 

        case 4: valor_base = 500.00; break; 

        default: valor_base = 0; break; 

    } 

  

    // Verifica descontos e acréscimos 

    int idade = 2024 - atoi(&cliente.data_nascimento[6]); 

    if (cliente.sexo == 1 && idade >= 13 && idade < 35) { 

        valor_base += valor_base * 0.30; // Acréscimo de 30% 

    } 

    if (cliente.num_dependentes > 1) { 

        valor_base -= valor_base * 0.20; // Desconto de 20% 

    } 

    if (idade < 13) { 

        valor_base -= valor_base * 0.30; // Desconto de 30% 

    } 

    if (idade >= 60) { 

        valor_base += valor_base * 0.40; // Acréscimo de 40% 

    } 

  

    return valor_base; 

} 

  

void cadastrar_cliente(FILE *arquivo) { 

    Cliente cliente; 

  

    printf("CPF: "); 

    fgets(cliente.cpf, sizeof(cliente.cpf), stdin); 

    cliente.cpf[strcspn(cliente.cpf, "\n")] = '\0'; // Remove o newline 

    getchar(); // Espera pelo input 

  

    printf("Nome: "); 

    fgets(cliente.nome, sizeof(cliente.nome), stdin); 

    cliente.nome[strcspn(cliente.nome, "\n")] = '\0';  

    getchar();  

  

    printf("Sexo (1-fem/2-masc): "); 

    scanf("%d", &cliente.sexo); 

    getchar(); // Limpa o newline deixado pelo scanf 

    getchar(); // Espera pelo input 

  

    printf("Email: "); 

    fgets(cliente.email, sizeof(cliente.email), stdin); 

    cliente.email[strcspn(cliente.email, "\n")] = '\0';  

    getchar();  

  

    printf("Data de Nascimento (dd/mm/yyyy): "); 

    fgets(cliente.data_nascimento, sizeof(cliente.data_nascimento), stdin); 

    cliente.data_nascimento[strcspn(cliente.data_nascimento, "\n")] = '\0';  

    getchar();  

  

    printf("Telefone: "); 

    fgets(cliente.telefone, sizeof(cliente.telefone), stdin); 

    cliente.telefone[strcspn(cliente.telefone, "\n")] = '\0';  

    getchar();  

  

    printf("CPF do Terceiro: "); 

    fgets(cliente.cpf_terceiro, sizeof(cliente.cpf_terceiro), stdin); 

    cliente.cpf_terceiro[strcspn(cliente.cpf_terceiro, "\n")] = '\0';  

    getchar();  

  

    printf("Nome do Terceiro: "); 

    fgets(cliente.nome_terceiro, sizeof(cliente.nome_terceiro), stdin); 

    cliente.nome_terceiro[strcspn(cliente.nome_terceiro, "\n")] = '\0';  

    getchar();  

  

    printf("Data de Nascimento do Terceiro (dd/mm/yyyy): "); 

    fgets(cliente.data_nascimento_terceiro, sizeof(cliente.data_nascimento_terceiro), stdin); 

    cliente.data_nascimento_terceiro[strcspn(cliente.data_nascimento_terceiro, "\n")] = '\0';  

    getchar();  

  

    printf("Data de Vencimento do Plano (dd/mm/yyyy): "); 

    fgets(cliente.data_vencimento_plano, sizeof(cliente.data_vencimento_plano), stdin); 

    cliente.data_vencimento_plano[strcspn(cliente.data_vencimento_plano, "\n")] = '\0';  

    getchar();  

  

    printf("Tipo de Plano (1 - Ouro, 2 - Diamante, 3 - Prata, 4 - Esmeralda): "); 

    scanf("%d", &cliente.tipo_plano); 

    getchar();  

    getchar();  

  

    printf("Número de Dependentes: "); 

    scanf("%d", &cliente.num_dependentes); 

    getchar();  

    getchar();  

  

    cliente.valor_plano = calcular_valor_plano(cliente); 

  

    fseek(arquivo, 0, SEEK_END); 

    fwrite(&cliente, sizeof(Cliente), 1, arquivo); 

    printf("Cliente cadastrado com sucesso!\n"); 

} 

  

void listar_clientes(FILE *arquivo) { 

    Cliente cliente; 

    rewind(arquivo); 

    printf("CPF\t\tNome\t\tSexo\tEmail\t\tData Nasc.\tTelefone\tValor Plano\tData Venc.\n"); 

    while (fread(&cliente, sizeof(Cliente), 1, arquivo)) { 

        printf("%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%s\n", 

cliente.cpf, cliente.nome, cliente.sexo, cliente.email, 

               cliente.data_nascimento, cliente.telefone, 

               cliente.valor_plano, cliente.data_vencimento_plano); 

    } 

} 

  

void editar_cliente(FILE *arquivo) { 

    Cliente cliente; 

    char cpf[15]; 

    int encontrado = 0; 

  

    printf("Digite o CPF do cliente que deseja editar: "); 

    fgets(cpf, sizeof(cpf), stdin); 

    cpf[strcspn(cpf, "\n")] = '\0'; // Remove a newline character 

  

    rewind(arquivo); 

    while (fread(&cliente, sizeof(Cliente), 1, arquivo)) { 

        if (strcmp(cliente.cpf, cpf) == 0) { 

            encontrado = 1; 

            break; 

        } 

    } 

  

    if (!encontrado) { 

        printf("Cliente não encontrado!\n"); 

        return; 

    } 

  

    printf("Editando cliente %s\n", cliente.nome); 

    printf("Novo Nome: "); 

    fgets(cliente.nome, sizeof(cliente.nome), stdin); 

    cliente.nome[strcspn(cliente.nome, "\n")] = '\0'; // Remove a newline character 

  

    printf("Novo Sexo (1-fem/2-masc): "); 

    scanf("%d", &cliente.sexo); 

    getchar(); // Clear the newline character left by scanf 

  

    printf("Novo Email: "); 

    fgets(cliente.email, sizeof(cliente.email), stdin); 

    cliente.email[strcspn(cliente.email, "\n")] = '\0'; // Remove a newline character 

  

    printf("Nova Data de Nascimento (dd/mm/yyyy): "); 

    fgets(cliente.data_nascimento, sizeof(cliente.data_nascimento), stdin); 

    cliente.data_nascimento[strcspn(cliente.data_nascimento, "\n")] = '\0'; // Remove a newline character 

  

    printf("Novo Telefone: "); 

    fgets(cliente.telefone, sizeof(cliente.telefone), stdin); 

    cliente.telefone[strcspn(cliente.telefone, "\n")] = '\0'; // Remove a newline character 

  

    printf("Novo CPF do Terceiro: "); 

    fgets(cliente.cpf_terceiro, sizeof(cliente.cpf_terceiro), stdin); 

    cliente.cpf_terceiro[strcspn(cliente.cpf_terceiro, "\n")] = '\0'; // Remove a newline character 

  

    printf("Novo Nome do Terceiro: "); 

    fgets(cliente.nome_terceiro, sizeof(cliente.nome_terceiro), stdin); 

    cliente.nome_terceiro[strcspn(cliente.nome_terceiro, "\n")] = '\0'; // Remove a newline character 

  

    printf("Nova Data de Nascimento do Terceiro (dd/mm/yyyy): "); 

    fgets(cliente.data_nascimento_terceiro, sizeof(cliente.data_nascimento_terceiro), stdin); 

    cliente.data_nascimento_terceiro[strcspn(cliente.data_nascimento_terceiro, "\n")] = '\0'; // Remove a newline character 

  

    printf("Nova Data de Vencimento do Plano (dd/mm/yyyy): "); 

    fgets(cliente.data_vencimento_plano, sizeof(cliente.data_vencimento_plano), stdin); 

    cliente.data_vencimento_plano[strcspn(cliente.data_vencimento_plano, "\n")] = '\0'; // Remove a newline character 

  

    printf("Novo Tipo de Plano (1 - Ouro, 2 - Diamante, 3 - Prata, 4 - Esmeralda): "); 

    scanf("%d", &cliente.tipo_plano); 

    getchar(); // Clear the newline character left by scanf 

  

    printf("Novo Número de Dependentes: "); 

    scanf("%d", &cliente.num_dependentes); 

    getchar(); // Clear the newline character left by scanf 

  

    cliente.valor_plano = calcular_valor_plano(cliente); 

  

    fseek(arquivo, -(long)sizeof(Cliente), SEEK_CUR); 

    fwrite(&cliente, sizeof(Cliente), 1, arquivo); 

    printf("Cliente atualizado com sucesso!\n"); 

} 

  

void remover_cliente(FILE *arquivo) { 

    Cliente cliente; 

    char cpf[15]; 

    FILE *temp = fopen("temp.txt", "w+b"); 

    if (!temp) { 

        printf("Erro ao abrir arquivo temporário!\n"); 

        return; 

    } 

  

    int encontrado = 0; 

  

    printf("Digite o CPF do cliente que deseja remover: "); 

    fgets(cpf, sizeof(cpf), stdin); 

    cpf[strcspn(cpf, "\n")] = '\0';  

  

    rewind(arquivo); 

    while (fread(&cliente, sizeof(Cliente), 1, arquivo)) { 

        if (strcmp(cliente.cpf, cpf) != 0) { 

            fwrite(&cliente, sizeof(Cliente), 1, temp); 

        } else { 

            encontrado = 1; 

        } 

    } 

  

    fclose(arquivo); 

    fclose(temp); 

  

    remove("clientes.txt"); 

    rename("temp.txt", "clientes.txt"); 

  

    arquivo = fopen("clientes.txt", "r+b"); 

  

    if (encontrado) { 

        printf("Cliente removido com sucesso!\n"); 

    } else { 

        printf("Cliente não encontrado!\n"); 

    } 

} 

  

void listar_clientes_por_plano(FILE *arquivo) { 

    Cliente cliente; 

    int tipo_plano; 

  

    printf("Digite o tipo de plano (1 - Ouro, 2 - Diamante, 3 - Prata, 4 - Esmeralda): "); 

    scanf("%d", &tipo_plano); 

    getchar(); 

  

    rewind(arquivo); 

    printf("CPF\t\tNome\t\tSexo\tEmail\t\tData Nasc.\tTelefone\tValor Plano\tData Venc.\n"); 

    while (fread(&cliente, sizeof(Cliente), 1, arquivo)) { 

        if (cliente.tipo_plano == tipo_plano) { 

            printf("%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%s\n", 

                   cliente.cpf, cliente.nome, cliente.sexo, cliente.email, 

                   cliente.data_nascimento, cliente.telefone, 

                   cliente.valor_plano, cliente.data_vencimento_plano); 

        } 

    } 

} 

  

void listar_vencimentos_do_mes(FILE *arquivo) { 

    Cliente cliente; 

    int mes, ano; 

  

    printf("Digite o mês de vencimento (1-12): "); 

    scanf("%d", &mes); 

    getchar(); 

    printf("Digite o ano de vencimento: "); 

    scanf("%d", &ano); 

    getchar(); 

  

    rewind(arquivo); 

    printf("CPF\t\tNome\t\tSexo\tEmail\t\tData Nasc.\tTelefone\tValor Plano\tData Venc.\n"); 

    while (fread(&cliente, sizeof(Cliente), 1, arquivo)) { 

        int mes_venc, ano_venc; 

        sscanf(cliente.data_vencimento_plano, "%*d/%d/%d", &mes_venc, &ano_venc); 

        if (mes_venc == mes && ano_venc == ano) { 

            printf("%s\t%s\t%d\t%s\t%s\t%s\t%.2f\t%s\n", 

                   cliente.cpf, cliente.nome, cliente.sexo, cliente.email, 

                   cliente.data_nascimento, cliente.telefone, 

                   cliente.valor_plano, cliente.data_vencimento_plano); 

        } 

    } 

} 

  

int main() { 

    FILE *arquivo = fopen("clientes.txt", "r+b"); 

    if (!arquivo) { 

        arquivo = fopen("clientes.txt", "w+b"); 

        if (!arquivo) { 

            printf("Erro ao abrir arquivo de clientes!\n"); 

            return 1; 

        } 

    } 

  

    int opcao; 

  

    do { 

        printf("\nNúcleo Seguros\n"); 

        printf("1 - Cadastrar Cliente\n"); 

        printf("2 - Editar Cliente\n"); 

        printf("3 - Remover Cliente\n"); 

        printf("4 - Listagem Geral\n"); 

        printf("5 - Listagem por Plano\n"); 

        printf("6 - Listagem dos Vencimentos do Plano de Saúde do mês\n"); 

        printf("0 - Sair\n"); 

        printf("Escolha uma opção: "); 

        scanf("%d", &opcao); 

        getchar(); 

  

        switch (opcao) { 

            case 1: cadastrar_cliente(arquivo); break; 

            case 2: editar_cliente(arquivo); break; 

            case 3: remover_cliente(arquivo); break; 

            case 4: listar_clientes(arquivo); break; 

            case 5: listar_clientes_por_plano(arquivo); break; 

            case 6: listar_vencimentos_do_mes(arquivo); break; 

            case 0: fclose(arquivo); break; 

            default: printf("Opção inválida!\n"); 

        } 

    } while (opcao != 0); 

  

    return 0; 

} 
