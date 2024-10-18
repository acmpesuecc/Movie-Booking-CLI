# Makefile to compile the movie booking program

# Compiler and flags
CC = gcc
CFLAGS = -Wall -g  # -Wall enables all compiler warnings, -g adds debugging symbols

# Target executable
TARGET = movie_booking

# List of object files needed to build the target
OBJS = main.o data_handler.o details_handler.o bill_handler.o menu_handler.o movie_booking.o


# Default target to build the program
all: $(TARGET)

# Rule to build the target executable by linking object files
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Rule to compile main.c into main.o
main.o: main.c movie_book.h
	$(CC) $(CFLAGS) -c main.c

# Rule to compile functions.c into functions.o
details_handler.o: details_handler.c movie_book.h
	$(CC) $(CFLAGS) -c details_handler.c

data_handler.o: data_handler.c movie_book.h
	$(CC) $(CFLAGS) -c data_handler.c

bill_handler.o: bill_handler.c movie_book.h
	$(CC) $(CFLAGS) -c bill_handler.c

menu_handler.o: menu_handler.c movie_book.h
	$(CC) $(CFLAGS) -c menu_handler.c

movie_booking.o: movie_booking.c movie_book.h
	$(CC) $(CFLAGS) -c movie_booking.c

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony target to prevent conflicts with files named 'clean'
.PHONY: clean all