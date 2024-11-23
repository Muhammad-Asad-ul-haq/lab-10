#include <stdio.h>


void sort(int num[], int size) {
    
    if (size == 1) {
        return;
    }

   
    for (int i = 0; i < size - 1; i++) {
        if (num[i] > num[i + 1]) {
           
            int temp = num[i];
            num[i] = num[i + 1];
            num[i + 1] = temp;
        }
    }

    
    sort(num, size - 1);
}

int main() {
    int size;

 
    printf("Enter the number of integers: ");
    scanf("%d", &size);

    int numbers[size];  

    
    printf("Enter the integers:\n");
    for (int i = 0; i < size; i++) {
        printf("Integer %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

  
    sort(numbers, size);

 
    printf("Integers in ascending order:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
