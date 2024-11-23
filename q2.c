#include <stdio.h>
#include <string.h>


void reverse(char str[], int first, int last) {
    if (first >= last) {
        return; 
    }

   
    char temp = str[first];
    str[first] = str[last];
    str[last] = temp;

   
    reverse(str, first + 1, last - 1);
}

int main() {
    char word[100];

    printf("Enter a word: ");
    gets(word);

   
    int length = strlen(word);
    if (word[length - 1] == '\n') {
        word[length - 1] = '\0';
    }

   
    reverse(word, 0, length - 1);

    printf("Reversed word: %s\n", word);

    return 0;
}