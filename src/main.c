#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    char email[50];
    char mobile[10];
    char *row;
    int col;
    char movie_selected[50];
} Details;

typedef struct {
    char *movie_name;
    char seats[10][15][4];
} Theatre;

Theatre *list = NULL;
Details *dynamic_array = NULL;
int count = 0;
Theatre one, two, three, four, five;

void WriteBookingToCSV(const Details* booking) {
    FILE* file = fopen("data.csv", "a");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }

    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    char datetime[25];
    strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M:%S", t);
    
    // Include ALL fields and consistent order
    fprintf(file, "%s,%s,%s,%s,%c,%d,%s\n",
            booking->name,
            booking->email,
            booking->mobile,  // Added mobile
            booking->movie_selected,
            *(booking->row),
            booking->col,
            datetime);
    
    fflush(file);  // Ensure data is written immediately
    fclose(file);
}

void ResetBookings() {
    // Clear CSV file
    FILE* file = fopen("data.csv", "w");
    if (!file) {
        printf("Error resetting bookings!\n");
        return;
    }
    fprintf(file, "name,email,mobile,movie,row,col,datetime\n");
    fclose(file);
    
    // Clear memory
    for (int i = 0; i < count; i++) {
        if (dynamic_array[i].row != NULL) {
            free(dynamic_array[i].row);
        }
    }
    free(dynamic_array);
    dynamic_array = malloc(sizeof(Details));
    if (dynamic_array == NULL) {
    printf("Memory allocation failed during reset!\n");
    return;
    }
    count = 0;
    
    // Reset seats
    char *empty_seat = "[ ]";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 15; j++) {
            strcpy(one.seats[i][j], empty_seat);
            strcpy(two.seats[i][j], empty_seat);
            strcpy(three.seats[i][j], empty_seat);
            strcpy(four.seats[i][j], empty_seat);
            strcpy(five.seats[i][j], empty_seat);
        }
    }
    
    printf("\033[1;32m");
    printf("\nAll bookings have been reset!\n");
    printf("\033[0m");
}

void PrintMenu() {
    printf("\033[1;36m");
    printf("   ╔════════════════════════════════════════════════════════════╗\n");
    printf("   ║                                                            ║\n");
    printf("   ║                         BOOK YOUR SHOW                     ║\n");
    printf("   ║                                                            ║\n");
    printf("   ║  Please select an option from below:                       ║\n");
    printf("   ║                                                            ║\n");
    printf("   ║    (1) Enter Details                                       ║\n");
    printf("   ║    (2) Show Details                                        ║\n");
    printf("   ║    (3) Book Movies                                         ║\n");
    printf("   ║    (4) Generate Bill                                       ║\n");
    printf("   ║    (5) Reset All Bookings                                  ║\n");
    printf("   ║    (6) Exit                                                ║\n");
    printf("   ║                                                            ║\n");
    printf("   ╚════════════════════════════════════════════════════════════╝\n");
    printf("   > ");
    printf("\033[0m");
}

void InputDetails() {
    Details *temp = realloc(dynamic_array, (count + 1) * sizeof(Details));
    if (temp == NULL) {
        printf("\n Memory allocation failed !");
        return;
    }
    dynamic_array = temp;

    printf("   >>> Enter your name: ");
    scanf(" %[^\n]", dynamic_array[count].name);
    getchar();
    printf("   >>> Enter your email address:");
    scanf("%s", dynamic_array[count].email);
    getchar();
    printf("   >>> Enter mobile number: ");
    scanf("%s", dynamic_array[count].mobile);
    getchar();

    count++;
}

void ShowDetails() {
    printf("   >>> Enter first or last name: ");
    char search[50];
    scanf("%s", search);
    for (int i = 0; i < count; i++) {
        if (strstr(dynamic_array[i].name, search) != NULL) {
            printf("   Name: %s\n   Mobile: %s\n   Email: %s\n", 
                   dynamic_array[i].name, dynamic_array[i].mobile, dynamic_array[i].email);
        }
    }
}

void ReadCSVAndUpdateSeats(const char *filename, Theatre *theatre, char *moviename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return;  // Silent fail - file might not exist first time
    }

    char line[256];
    fgets(line, sizeof(line), file);  // Skip header
    
    while (fgets(line, sizeof(line), file)) {
        char *token;
        char movie[50], row;
        int col;
        
        // Parse: name,email,mobile,movie,row,col,datetime
        token = strtok(line, ",");  // name
        if (!token) continue;
        
        token = strtok(NULL, ",");  // email
        if (!token) continue;
        
        token = strtok(NULL, ",");  // mobile
        if (!token) continue;
        
        token = strtok(NULL, ",");  // movie
        if (token) strcpy(movie, token);
        
        token = strtok(NULL, ",");  // row
        if (token) row = token[0];
        
        token = strtok(NULL, ",");  // col
        if (token) col = atoi(token);
        
        if (strcmp(movie, moviename) == 0) {
            int row_index = row - 'A';
            if (row_index >= 0 && row_index < 10 && col >= 1 && col <= 15) {
                strcpy(theatre->seats[row_index][col - 1], "[X]");
            }
        }
    }
    fclose(file);
}

void Book() {
    printf("   >>> Enter your first or last name: ");
    char search[50];
    scanf("%s", search);
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(dynamic_array[i].name, search) != NULL) {
            found = 1;
            printf("   Which Movie would you like to watch:\n");
            printf("   \t(1) Dune 2\n");
            printf("   \t(2) Transformers One\n");
            printf("   \t(3) Oppenheimer\n");
            printf("   \t(4) Inception\n");
            printf("   \t(5) Tenet\n");
            printf("   >>> ");
            
            int n;
            scanf("%d", &n);
            char movie_chosen[50];
            int movie_num;
            
            switch(n) {
                case 1:
                    strcpy(movie_chosen, "Dune 2");
                    movie_num = 1;
                    break;
                case 2:
                    strcpy(movie_chosen, "Transformers One");
                    movie_num = 2;
                    break;
                case 3:
                    strcpy(movie_chosen, "Oppenheimer");
                    movie_num = 3;
                    break;
                case 4:
                    strcpy(movie_chosen, "Inception");
                    movie_num = 4;
                    break;
                case 5:
                    strcpy(movie_chosen, "Tenet");
                    movie_num = 5;
                    break;
                default:
                    printf("Invalid selection!\n");
                    return;
            }
            
            // Update seats from CSV before showing available seats
            switch (movie_num) {
                case 1:
                    ReadCSVAndUpdateSeats("data.csv", &one, movie_chosen);
                    break;
                case 2:
                    ReadCSVAndUpdateSeats("data.csv", &two, movie_chosen);
                    break;
                case 3:
                    ReadCSVAndUpdateSeats("data.csv", &three, movie_chosen);
                    break;
                case 4:
                    ReadCSVAndUpdateSeats("data.csv", &four, movie_chosen);
                    break;
                case 5:
                    ReadCSVAndUpdateSeats("data.csv", &five, movie_chosen);
                    break;
            }
            
            char s;
            char *empty_seat = "[ ]";
            char *booked_seat = "[X]";
            Theatre *current_theatre;
            
            switch(n) {
                case 1:
                    current_theatre = &one;
                    break;
                case 2:
                    current_theatre = &two;
                    break;
                case 3:
                    current_theatre = &three;
                    break;
                case 4:
                    current_theatre = &four;
                    break;
                case 5:
                    current_theatre = &five;
                    break;
                default:
                    return;
            }
            
            strcpy(dynamic_array[i].movie_selected, movie_chosen);
            printf("   You have chosen the movie %s\n", movie_chosen);
            printf("   Select a Seat!\n");

            // Display seat layout
            printf("\t\tRecliner $500\n");
            for (int i = 9; i > 8; i--) {
                printf("\033[38;5;250m");
                printf("\t\t%c ", 'A' + i);
                printf("\033[0m");
                for (int j = 0; j < 15; j++) {
                    if (strcmp(current_theatre->seats[i][j], empty_seat) == 0)
                        printf("\033[1;32m");
                    else
                        printf("\033[1;31m");
                    printf("%s ", current_theatre->seats[i][j]);
                }
                printf("\033[0m");
                printf("\n");
            }
            
            printf("\t\tPrime $300\n");
            for (int i = 8; i > 5; i--) {
                printf("\033[38;5;250m");
                printf("\t\t%c ", 'A' + i);
                printf("\033[0m");
                for (int j = 0; j < 15; j++) {
                    if (strcmp(current_theatre->seats[i][j], empty_seat) == 0)
                        printf("\033[1;32m");
                    else
                        printf("\033[1;31m");
                    printf("%s ", current_theatre->seats[i][j]);
                }
                printf("\033[0m");
                printf("\n");
            }
            
            printf("\t\tNormal $200\n");
            for (int i = 5; i >= 0; i--) {
                printf("\033[38;5;250m");
                printf("\t\t%c ", 'A' + i);
                printf("\033[0m");
                for (int j = 0; j < 15; j++) {
                    if (strcmp(current_theatre->seats[i][j], empty_seat) == 0)
                        printf("\033[1;32m");
                    else
                        printf("\033[1;31m");
                    printf("%s ", current_theatre->seats[i][j]);
                }
                printf("\033[0m");
                printf("\n");
            }
            
            printf("\t\t   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15\n\n");
            
            printf("   >>> Enter the row you would like (A-J): ");
            scanf(" %c", &s);
            printf("   >>> Enter the seat number you would like (1-15): ");
            int num;
            scanf("%d", &num);

            // Validate input
            if (s < 'A' || s > 'J' || num < 1 || num > 15) {
                printf("Invalid seat selection!\n");
                return;
            }

            int temp = s - 'A';
            
            // Check if seat is already booked
            if (strcmp(current_theatre->seats[temp][num - 1], booked_seat) == 0) {
                printf("Seat already booked! Please choose another seat.\n");
                return;
            }

            strcpy(current_theatre->seats[temp][num - 1], booked_seat);

            // Allocate memory for row and store booking
            dynamic_array[i].row = malloc(sizeof(char));
            if (dynamic_array[i].row == NULL) {
                printf("Memory allocation failed!\n");
                return;
            }
            *(dynamic_array[i].row) = s;
            dynamic_array[i].col = num;
            
            WriteBookingToCSV(&dynamic_array[i]);
            WriteBookingToJSON(&dynamic_array[i]);
            printf("Booking successful!\n");
        }
    }
    
    if (!found) {
        printf("No user found with that name!\n");
    }
}

void GenerateBill() {
    printf("   >>> Enter first or last name: ");
    char search[50];
    scanf("%s", search);
    
    int found = 0;
    printf("\033[0;31m");
    for (int i = 0; i < count; i++) {
        if (strstr(dynamic_array[i].name, search) != NULL) {
            found = 1;
            printf("\n\n\t\t   *************************************\n");
            printf("\t\t     * Name : %s\n", dynamic_array[i].name);
            printf("\t\t     * Email id : %s\n", dynamic_array[i].email);
            printf("\t\t     * Mobile No : %s\n", dynamic_array[i].mobile);
            
            time_t currentTime;
            struct tm *localTime;
            currentTime = time(NULL);
            localTime = localtime(&currentTime);
            printf("\t\t     * %s", asctime(localTime));
            
            printf("\t\t     * Movie Selected: %s\n", dynamic_array[i].movie_selected);
            printf("\t\t     * Seat : %c-%d\n", *(dynamic_array[i].row), dynamic_array[i].col);
            
            if ('A' <= *(dynamic_array[i].row) && *(dynamic_array[i].row) <= 'F')
                printf("\t\t     * Price = $200\n");
            else if ('G' <= *(dynamic_array[i].row) && *(dynamic_array[i].row) <= 'I')
                printf("\t\t     * Price = $300\n");
            else if (*(dynamic_array[i].row) == 'J')
                printf("\t\t     * Price = $500\n");
                
            printf("\t\t   *************************************\n\n");
        }
    }
    printf("\033[0m");
    
    if (!found) {
        printf("No bookings found for that name!\n");
    }
}

void LoadAllBookingsFromCSV() {
    FILE *file = fopen("data.csv", "r");
    if (!file) {
        return;  // File doesn't exist yet
    }

    char line[256];
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return;  // Empty file
    }
    
    while (fgets(line, sizeof(line), file)) {
        char *token;
        
        // Parse all fields
        token = strtok(line, ",");
        if (!token) continue;
        
        // Resize dynamic array
        Details *temp = realloc(dynamic_array, (count + 1) * sizeof(Details));
        if (!temp) {
            printf("Memory allocation failed during CSV load!\n");
            fclose(file);
            return;
        }
        dynamic_array = temp;
        
        // Store directly in dynamic_array[count]
        strcpy(dynamic_array[count].name, token);
        
        token = strtok(NULL, ",");
        if (token) strcpy(dynamic_array[count].email, token);
        
        token = strtok(NULL, ",");
        if (token) strcpy(dynamic_array[count].mobile, token);
        
        token = strtok(NULL, ",");
        if (token) strcpy(dynamic_array[count].movie_selected, token);
        
        token = strtok(NULL, ",");
        if (token) {
            dynamic_array[count].row = malloc(sizeof(char));
            if (dynamic_array[count].row) {
                *(dynamic_array[count].row) = token[0];
            }
        }
        
        token = strtok(NULL, ",");
        if (token) dynamic_array[count].col = atoi(token);
        
        count++;
    }
    fclose(file);
}

void WriteBookingToJSON(const Details* booking) {
    FILE* file = fopen("bookings.json", "a");
    if (!file) {
        // Create new file with array start
        file = fopen("bookings.json", "w");
        if (!file) {
            printf("Error creating JSON file!\n");
            return;
        }
        fprintf(file, "[\n");
        fclose(file);
        file = fopen("bookings.json", "a");
    }
    
    // Get file size to determine if we need comma
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    // Read last few characters to check if array is empty
    char last_chars[10] = {0};
    if (size > 5) {
        fseek(file, size - 5, SEEK_SET);
        fread(last_chars, 1, 5, file);
    }
    
    fseek(file, 0, SEEK_END);
    
    // Add comma if not first element
    if (size > 10 && strstr(last_chars, "]") == NULL) {
        fprintf(file, ",\n");
    }
    
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    char datetime[25];
    strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M:%S", t);
    
    fprintf(file, "  {\n");
    fprintf(file, "    \"name\": \"%s\",\n", booking->name);
    fprintf(file, "    \"email\": \"%s\",\n", booking->email);
    fprintf(file, "    \"mobile\": \"%s\",\n", booking->mobile);
    fprintf(file, "    \"movie\": \"%s\",\n", booking->movie_selected);
    fprintf(file, "    \"row\": \"%c\",\n", *(booking->row));
    fprintf(file, "    \"col\": %d,\n", booking->col);
    fprintf(file, "    \"datetime\": \"%s\"\n", datetime);
    fprintf(file, "  }");
    
    fflush(file);
    fclose(file);
}

void FinalizeJSONFile() {
    FILE* file = fopen("bookings.json", "a");
    if (file) {
        fprintf(file, "\n]");
        fclose(file);
    }
}

void ResetJSONBookings() {
    FILE* file = fopen("bookings.json", "w");
    if (file) {
        fprintf(file, "[]");
        fclose(file);
    }
}

int main() {
    // Initialize movie names
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

    // Initialize all seats as empty
    char *empty_seat = "[ ]";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 15; j++) {
            strcpy(one.seats[i][j], empty_seat);
            strcpy(two.seats[i][j], empty_seat);
            strcpy(three.seats[i][j], empty_seat);
            strcpy(four.seats[i][j], empty_seat);
            strcpy(five.seats[i][j], empty_seat);
        }
    }

    // Initialize dynamic array
    dynamic_array = malloc(sizeof(Details));
    if (dynamic_array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Load existing bookings from CSV
    LoadAllBookingsFromCSV();
    
    // Update seat maps for all movies
    ReadCSVAndUpdateSeats("data.csv", &one, "Dune 2");
    ReadCSVAndUpdateSeats("data.csv", &two, "Transformers One");
    ReadCSVAndUpdateSeats("data.csv", &three, "Oppenheimer");
    ReadCSVAndUpdateSeats("data.csv", &four, "Inception");
    ReadCSVAndUpdateSeats("data.csv", &five, "Tenet");

    // Main menu loop
    int flag = 0;
    while (flag != 1) {
        PrintMenu();
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
                ResetBookings();
                break;
            case 6:
                flag = 1;
                break;
            default:
                printf("Invalid entry!!!\n");
                break;
        }
    }

    // Free allocated memory
    for (int i = 0; i < count; i++) {
        if (dynamic_array[i].row != NULL) {
            free(dynamic_array[i].row);
        }
    }
    free(dynamic_array);
    free(one.movie_name);
    free(two.movie_name);
    free(three.movie_name);
    free(four.movie_name);
    free(five.movie_name);
    
    FinalizeJSONFile();
    return 0;
}