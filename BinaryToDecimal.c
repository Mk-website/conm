#include <stdio.h>
#include<math.h>
void printDecimal(int num)
{
    int dec = 0, i = 0;
    while (num > 0)
    {
        dec += (num%10)*pow(2, i);
        num /= 10;
        i++;
    }
    printf("%d", dec);
}
int main(){
    int num;
    printf("Enter Binary Number: \n");
    scanf("%d", &num);
    if (num < 0) {
        printf("Please enter a non-negative integer.\n");
        return 0;
    }
    printf("Decimal for %d is ", num);
    printDecimal(num);
    return 0;
}