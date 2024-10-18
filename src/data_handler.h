// movie_booking.h

#ifndef MOVIE_BOOKING_H
#define MOVIE_BOOKING_H

// Define the Theatre structure
typedef struct {
    char seats[10][15][4];  // 10 rows, 15 columns, seat state (e.g., "[X]" or "[ ]")
} Theatre;

// Function declaration for reading CSV and updating seats
void ReadCSVAndUpdateSeats(const char *filename, Theatre *theatre, char *moviename);

#endif /* MOVIE_BOOKING_H */
