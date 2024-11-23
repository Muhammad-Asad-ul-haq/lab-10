#include <stdio.h>
#define conversionConstant 0.001

float convert_meter_to_kilometer(float value) {
    static int Count = 0;  
    Count++;  
    printf("Function 'convert_meter_to_kilometer' has been called %d times.\n", Count);
    return value * conversionConstant;
}

int main() {
    float m, km;
    char check;

    do {
        printf("\nEnter distance in meters: ");
        scanf("%f", &m);
        km = convert_meter_to_kilometer(m);
        printf("%.2f meters = %.4f kilometers.\n", m, km);
        printf("Enter 'p' to exit the program or any other key to continue: ");
        scanf(" %c", &check);
    } while (check != 'p' && check != 'P');

    printf("\nProgram exited. Thankyou for visiting!\n");
    return 0;
}


