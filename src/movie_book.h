// movie_booking.h

#ifndef MOVIE_BOOK_H
#define MOVIE_BOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLUMNS 15

typedef struct {
    char name[50];
    char email[50];
    char mobile[10];
    char *row;
    int col;
    char movie_selected[50];
} Details;

// Structure to store movie details
typedef struct {
    char *movie_name;
    char seats[ROWS][COLUMNS][4]; // 10 rows, 15 seats per row
} Theatre;

// Structure for customer details
// typedef struct {
//     char name[50];
//     char movie_booked[50];
//     char seat_row;
//     int seat_col;
// } Details;

extern int count;

extern Theatre one, two, three, four, five;
extern Details *dynamic_array;

// Function declarations
void PrintMenu();
void InputDetails();
void ShowDetails();
void Book();
void GenerateBill();
void ReadCSVAndUpdateSeats(const char *filename, Theatre *theatre, char *moviename);

#endif /* MOVIE_BOOKING_H */
