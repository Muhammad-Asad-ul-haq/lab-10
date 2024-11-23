#include <stdio.h>

int linearSearch(int arr[], int value, int size, int index) {
    if (index >= size) {
        return -1;  
    }

    if (arr[index] == value) {
        return index + 1;  
    }

    return linearSearch(arr, value, size, index + 1); 
}

int main() {
    int size, value, index = 0;

    printf("Enter size of the array: ");
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter value to search: ");
    scanf("%d", &value);

    int result = linearSearch(arr, value, size, index);

    if (result != -1) {
        printf("Element %d found at position %d.\n", value, result);
    } else {
        printf("Element %d not found in the array.\n", value);
    }

    return 0;
}

