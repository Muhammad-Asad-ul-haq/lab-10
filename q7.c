#include <stdio.h>
#define maxTemp 45.00

void temprature(float temp[], int size) {
    static int count = 0;

    for (int i = 0; i < size; i++) {
        if (temp[i] > maxTemp) {
            count++;
        }
    }

    printf("%d times the temperature has exceeded the max temperature of %.1f°C.\n", count, maxTemp);
}

int main() {
    int size;

    printf("Enter the number of temperatures: ");
    scanf("%d", &size);

    float celcius[size];

    printf("Enter the temperatures (in Celsius):\n");
    for (int i = 0; i < size; i++) {
        printf("Temperature %d: ", i + 1);
        scanf("%f", &celcius[i]);
    }

    temprature(celcius, size);

    return 0;
}
