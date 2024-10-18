// file_operations.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_booking.h"
#include "movie_book.h"

// Function to read CSV and update seats
void ReadCSVAndUpdateSeats(const char *filename, Theatre *theatre, char *moviename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s for reading.\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *token;
        char movie[50], row;
        int col;
        
        // Read movie details from CSV
        token = strtok(line, ",");    // First column (skip)
        token = strtok(NULL, ",");    // Second column (skip)
        token = strtok(NULL, ",");    // Third column (skip)
        token = strtok(NULL, ",");    // Fourth column (movie name)
        if (token) strcpy(movie, token);
        
        token = strtok(NULL, ",");    // Fifth column (row letter)
        if (token) row = token[0];
        
        token = strtok(NULL, ",");    // Sixth column (seat number)
        if (token) col = atoi(token);

        // Check if the movie matches and update seats
        if (strcmp(movie, moviename) == 0) {
            int row_index = row - 'A'; // Convert row letter to index
            if (row_index >= 0 && row_index < 10 && col >= 1 && col <= 15) {
                strcpy(theatre->seats[row_index][col - 1], "[X]");  // Mark seat as occupied
            }
        }
    }

    fclose(file);  // Close the file
}
