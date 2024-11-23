#include <stdio.h>

int sum(int n) {
   
    if (n <= 0) {
        return 0;
    }
   
    return (n % 10) + sum(n / 10);
}

int main() {
    int number;

    printf("Enter your Number (Positive) : ");
    scanf("%d", &number);

    
    if (number <= 0) {
        printf("Please enter a positive number.\n");
    } else {
        printf("The sum of digits of %d is %d\n", number, sum(number));
    }

    return 0;
}
