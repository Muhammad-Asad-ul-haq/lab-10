#include <stdio.h>
#include <string.h>

#define MAX 150  // Maximum number of movies that can be stored

struct Movie{
    char title[100];
    char genre[50];
    char director[50];
    int releaseYear;
    int rating;
};



void search(struct Movie movies[], int Count) {
    char genre[50];
    printf("\nEnter genre to search for: ");
    getchar();  
    gets(genre);

    printf("Movies in the genre '%s':\n", genre);
    int found = 0;
    for (int i = 0; i < Count; i++) {
        if (strcmp(movies[i].genre, genre) == 0) {
            printf("Title: %s | Director: %s | Release Year: %d | Rating: %d",movies[i].title, movies[i].director, movies[i].releaseYear, movies[i].rating);
            found = 1;
        }
    }
    if (found==0) {
        printf("No movies found in this genre.\n");
    }
}

void display(struct Movie movies[], int Count) {
    if (Count == 0) {
        printf("\nNo movies available.\n");
        return;
    }

    printf("\nAll Movies:\n");
    for (int i = 0; i < Count; i++) {
        printf("Movie %d:\n", i + 1);
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Director: %s\n", movies[i].director);
        printf("Release Year: %d\n", movies[i].releaseYear);
        printf("Rating: %d\n", movies[i].rating);
    }
}

void addMovie(struct Movie movies[], int *Count) {
    if (*Count >= MAX) {
        printf("Maximum movie limit reached.\n");
        return;
    }

    printf("\nEnter movie details:\n");
    printf("Title: ");
    getchar();  
    gets(movies[*Count].title);
    printf("Genre: ");
    gets(movies[*Count].genre);
    printf("Director: ");
    gets(movies[*Count].director);
    printf("Release Year: ");
    scanf("%d", &movies[*Count].releaseYear);
    printf("Rating (0- 10): ");
    scanf("%d", &movies[*Count].rating);

    (*Count)++;
    printf("Movie added successfully!\n");
}

int main() {
    struct Movie movies[MAX];
    int Count = 0;
    int choice;

    do {
        printf("\nMovie Management System\n");
        printf("1. Add a New Movie\n");
        printf("2. Search Movies by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &Count);
                break;
            case 2:
                search(movies, Count);
                break;
            case 3:
                display(movies, Count);
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
