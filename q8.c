#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct car {
    char make[20];
    char model[20];
    int year;
    int mileage;
};

int main() {
    int i = 0, end = 0, x, choice, choice2;
    char make_[20];
    char model_[20];
    struct car cars[10];

    while (end == 0) {
        printf("\nMenu:\n");
        printf("1. Add a new car\n");
        printf("2. Display list of available cars\n");
        printf("3. Search for cars by make or model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();

        switch (choice) {
            case 1:
                if (i >= 10) {
                    printf("Car list is full! Cannot add more cars.\n");
                    break;
                }
                printf("Enter make of the car: ");
                fgets(cars[i].make, 20, stdin);
                cars[i].make[strcspn(cars[i].make, "\n")] = '\0';

                printf("Enter model of the car: ");
                fgets(cars[i].model, 20, stdin);
                cars[i].model[strcspn(cars[i].model, "\n")] = '\0';

                printf("Enter year of the car: ");
                if (scanf("%d", &cars[i].year) != 1) {
                    printf("Invalid input. Year should be a number.\n");
                    while (getchar() != '\n');
                    continue;
                }

                printf("Enter mileage of the car: ");
                if (scanf("%d", &cars[i].mileage) != 1) {
                    printf("Invalid input. Mileage should be a number.\n");
                    while (getchar() != '\n');
                    continue;
                }

                i++;
                printf("Car added successfully!\n");
                break;

            case 2:
                if (i == 0) {
                    printf("No cars available.\n");
                } else {
                    for (x = 0; x < i; x++) {
                        printf("\nCar no.%d\n", x + 1);
                        printf("Make: %s\n", cars[x].make);
                        printf("Model: %s\n", cars[x].model);
                        printf("Year: %d\n", cars[x].year);
                        printf("Mileage: %d\n", cars[x].mileage);
                    }
                }
                break;

            case 3:
                printf("Enter 1 to search by make\nEnter 2 to search by model\nEnter your choice: ");
                if (scanf("%d", &choice2) != 1) {
                    printf("Invalid input. Please enter 1 or 2.\n");
                    while (getchar() != '\n');
                    continue;
                }
                getchar();

                if (choice2 == 1) {
                    printf("Enter make: ");
                    fgets(make_, 20, stdin);
                    make_[strcspn(make_, "\n")] = '\0';

                    int found = 0;
                    for (x = 0; x < i; x++) {
                        if (strcasecmp(cars[x].make, make_) == 0) {
                            printf("\nCar no.%d\n", x + 1);
                            printf("Make: %s\n", cars[x].make);
                            printf("Model: %s\n", cars[x].model);
                            printf("Year: %d\n", cars[x].year);
                            printf("Mileage: %d\n", cars[x].mileage);
                            found = 1;
                        }
                    }
                    if (!found) {
                        printf("No cars found with make '%s'.\n", make_);
                    }
                } else if (choice2 == 2) {
                    printf("Enter model: ");
                    fgets(model_, 20, stdin);
                    model_[strcspn(model_, "\n")] = '\0';

                    int found = 0;
                    for (x = 0; x < i; x++) {
                        if (strcasecmp(cars[x].model, model_) == 0) {
                            printf("\nCar no.%d\n", x + 1);
                            printf("Make: %s\n", cars[x].make);
                            printf("Model: %s\n", cars[x].model);
                            printf("Year: %d\n", cars[x].year);
                            printf("Mileage: %d\n", cars[x].mileage);
                            found = 1;
                        }
                    }
                    if (!found) {
                        printf("No cars found with model '%s'.\n", model_);
                    }
                } else {
                    printf("Invalid choice.\n");
                }
                break;

            case 4:
                end = 1;
                printf("Exiting the program. Thankyou for Coming!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
