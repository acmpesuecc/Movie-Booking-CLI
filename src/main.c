#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   git 
#include "movies.h"
#include "seatmap.h"
#include "details.h"
#include "io.h"

int main() {
    Theatre theatres[5] = {
        {.movie_name = "Dune 2"},
        {.movie_name = "Transformers"},
        {.movie_name = "Civil War"},
        {.movie_name = "Kung Fu Panda"},
        {.movie_name = "Oppenheimer"}
    };

    for (int i = 0; i < 5; i++)
        initialize_seats(&theatres[i]);

    read_csv_update(theatres, 5);

    printf("Available Movies:\n");
    for (int i = 0; i < 5; i++)
        printf("%d. %s\n", i + 1, theatres[i].movie_name);

    int choice;
    printf("Select movie: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > 5) return 0;

    display_seats(&theatres[choice - 1]);

    Details d;
    input_details(&d);
    char more = 'Y';
while (toupper(more) == 'Y') {
    printf("Enter seat row and number (e.g., A 5): ");
    char row; int col;
    scanf(" %c %d", &row, &col);
    row = toupper(row);

    if (book_seat(&theatres[choice - 1], row, col)) {
        snprintf(d.movie_selected, sizeof(d.movie_selected), "%s", theatres[choice - 1].movie_name);
        d.row = row;  // if row is char in Details
        d.col = col;
        write_booking_to_csv(&d);
        printf("✅ Seat %c%d booked successfully!\n", row, col);
    } else {
        printf("❌ Seat already booked or invalid.\n");
    }

    display_seats(&theatres[choice - 1]); // update map after each seat
    printf("Do you want to book another seat? (Y/N): ");
    scanf(" %c", &more);
}
    return 0;
}
