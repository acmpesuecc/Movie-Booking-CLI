#ifndef SEATMAP_H
#define SEATMAP_H

#include "movies.h"
#include "details.h" 

void initialize_seats(Theatre *t);
void display_seats(Theatre *t);
int book_seat(Theatre *t, char row, int col);

void read_csv_update(Theatre *theatres, int count);
void write_booking_to_csv(Details *d);

#endif
