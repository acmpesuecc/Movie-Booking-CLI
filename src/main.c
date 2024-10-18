// main.c

#include "movie_book.h"

// Global variables for theatres and dynamic array
Theatre one, two, three, four, five;
Details *dynamic_array = NULL;

int main() {
    // Dynamically allocate memory for movie names
    one.movie_name = malloc(strlen("Dune 2") + 1);
    strcpy(one.movie_name, "Dune 2");
    two.movie_name = malloc(strlen("Transformers One") + 1);
    strcpy(two.movie_name, "Transformers One");
    three.movie_name = malloc(strlen("Oppenheimer") + 1);
    strcpy(three.movie_name, "Oppenheimer");
    four.movie_name = malloc(strlen("Inception") + 1);
    strcpy(four.movie_name, "Inception");
    five.movie_name = malloc(strlen("Tenet") + 1);
    strcpy(five.movie_name, "Tenet");

    char *empty_seat = "[ ]";

    // Initialize all seats to empty
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            strcpy(one.seats[i][j], empty_seat);
            strcpy(two.seats[i][j], empty_seat);
            strcpy(three.seats[i][j], empty_seat);
            strcpy(four.seats[i][j], empty_seat);
            strcpy(five.seats[i][j], empty_seat);
        }
    }

    // Allocate memory for customer details dynamically
    dynamic_array = malloc(sizeof(Details));
    if (dynamic_array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int flag = 0;
    while (flag != 1) {
        PrintMenu();  // Display menu options
        int n;
        scanf("%d", &n);

        switch (n) {
            case 1:
                InputDetails();
                break;
            case 2:
                ShowDetails();
                break;
            case 3:
                Book();
                break;
            case 4:
                GenerateBill();
                break;
            case 5:
                flag = 1;
                break;
            default:
                printf("Invalid entry!!!\n");
                break;
        }
    }

    // Free dynamically allocated memory
    free(one.movie_name);
    free(two.movie_name);
    free(three.movie_name);
    free(four.movie_name);
    free(five.movie_name);
    free(dynamic_array);

    return 0;
}
