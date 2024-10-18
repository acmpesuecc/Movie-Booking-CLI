#include <stdio.h>
#include <stdlib.h>
#include "details_handler.h"
#include "movie_book.h"

// typedef struct {
//     char name[50];
//     char email[50];
//     char mobile[10];
//     char movie_selected[50];
// } Details;
/*
// Global dynamic array to store user details

int count = 0;
*/
//Details *dynamic_array = NULL;
// Function to enter user details

void InputDetails() {
    dynamic_array = realloc(dynamic_array, (count + 1) * sizeof(Details));
    if (!dynamic_array) {
        printf("Memory allocation failed!\\n");
        exit(1);
    }

    printf("Enter Name: ");
    scanf("%s", dynamic_array[count].name);
    printf("Enter Email: ");
    scanf("%s", dynamic_array[count].email);
    printf("Enter Mobile: ");
    scanf("%s", dynamic_array[count].mobile);
    printf("Enter Movie Selected: ");
    scanf("%s", dynamic_array[count].movie_selected);

    count++;
    printf("Details entered successfully!\\n");
}

// Function to show user details
void ShowDetails() {
    if (count == 0) {
        printf("No details to show!\\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Email: %s, Mobile: %s, Movie: %s\\n",
               dynamic_array[i].name, dynamic_array[i].email,
               dynamic_array[i].mobile, dynamic_array[i].movie_selected);
    }
}