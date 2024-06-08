#include <stdio.h>
int main() {
  int total_installments;
  int total_instalments_paids;
  float installment_value;
  float debt_balance;
  int installments_to_pay;

 printf("Enter the total installments: ");
 scanf("%d", &total_installments);

 printf("Enter the total installments paid: ");
 scanf("%d", &total_instalments_paids);

 printf("Enter the value of each installment: ");
 scanf("%f", &installment_value);

 //Math 

 debt_balance = installment_value * (total_installments - total_instalments_paids);

 installments_to_pay = total_installments - total_instalments_paids;

 printf("Current outstanding balance: %.2f\n", debt_balance);
 printf("Number of installments without paying: %d\n", installments_to_pay);

return 0;  
}
