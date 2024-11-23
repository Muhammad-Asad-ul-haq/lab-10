#include <stdio.h>

void printArray(int arr[], int size) {
    if (size == 0){
        return;  
    }
    printf("%d ", arr[0]);  
    printArray(arr + 1, size - 1);  
}

int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements:\n");
    
    for (int i = 0; i < size; i++) 
    {
        printf("Number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    

    printArray(arr, size);
    printf("\n");

    return 0;
}

