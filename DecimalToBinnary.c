#include <stdio.h>

void printBinary(int num)
{
    if (num == 0)
        return;
    
    printBinary(num/2);
    printf("%d", num%2);
}

int main()
{
    int num;
    printf("Enter Decimal Number: \n");
    scanf("%d", &num);

    if (num < 0) {
        printf("Please enter a non-negative integer.\n");
        return 0;
    }
    printf("Binary for %d is ", num);
    printBinary(num);

    return 0;
}