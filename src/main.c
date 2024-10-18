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

typedef struct{
    char *movie_name;
    char seats[10][15][4];
} Theatre;

Theatre *list = NULL;

Details *dynamic_array = NULL;
int count = 0;

Theatre one, two, three, four, five;


void PrintMenu()
{
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
    printf("   ║    (5) Exit                                                ║\n");
    printf("   ║                                                            ║\n");
    printf("   ╚════════════════════════════════════════════════════════════╝\n");
    printf("   > ");
    printf("\033[0m");
}

void InputDetails()
{
    Details *temp = realloc(dynamic_array, (count + 1) * sizeof(Details));
    if (temp == NULL)
    {
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

void ShowDetails()
{
    printf("   >>> Enter first or last name: ");
    char search[50];
    scanf("%s", search);
    for (int i = 0; i < count; i++) {
        if (strstr(dynamic_array[i].name, search) != NULL) {
            printf("   Name: %s\n   Mobile: %s\n   Email: %s\n", dynamic_array[i].name, dynamic_array[i].mobile, dynamic_array[i].email);
        }
    }
}
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
        token = strtok(line,",");
        token = strtok(NULL,",");
        token = strtok(NULL,",");
        token = strtok(NULL, ",");
        if (token) strcpy(movie, token);
        token = strtok(NULL, ",");
        if (token) row = token[0];
        token = strtok(NULL, ",");
        if (token) col = atoi(token);
        if (strcmp(movie,moviename) == 0) {
            int row_index = row - 'A';
            if (row_index >= 0 && row_index < 10 && col >= 1 && col <= 15) {
                strcpy(theatre->seats[row_index][col - 1], "[X]");
            }
        }

    }
    fclose(file);
}
void Book()
{
    FILE *fp;
    fp = fopen("data.csv", "a");  // Open file in append mode
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return;
    }

    printf("   >>> Enter your first or last name: ");
    char search[50];
    scanf("%s", search);

    for (int i = 0; i < count; i++)
    {
        if (strstr(dynamic_array[i].name, search) != NULL)
        {
            // Display available movies
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
            switch(n)
            {
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
                    printf("Invalid option\n");
                    return;
            }

            // Prompt the user for seat selection
            printf("   >>> Enter row (A-J): ");
            char row;
            scanf(" %c", &row);  // Use space before %c to consume any newline

            printf("   >>> Enter seat number (1-15): ");
            int col;
            scanf("%d", &col);

            // Validate row and column input
            if (row < 'A' || row > 'J' || col < 1 || col > 15) {
                printf("Invalid seat selection.\n");
                return;
            }

            // Mark the seat as booked in the theater
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
                default:
                    break;
            }

            // Append booking details to the CSV file
            fprintf(fp, "%s,%s,%s,%s,%c,%d\n", dynamic_array[i].name, dynamic_array[i].email, dynamic_array[i].mobile, movie_chosen, row, col);
            printf("Booking confirmed: %s, Seat %c%d\n", movie_chosen, row, col);
        }
    }

    fclose(fp);  // Close the file
}

void GenerateBill()
{
    printf("   >>> Enter first or last name: ");
    char search[50];
    scanf("%s", search);
    printf("\033[0;31m");
    for (int i = 0; i < count; i++) {
        if (strstr(dynamic_array[i].name, search) != NULL)
        {
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
            if ('A'<=*(dynamic_array[i].row) && *(dynamic_array[i].row)<='F')
                printf("\t\t     * Price = $200\n");
            else if('G'<=*(dynamic_array[i].row) && *(dynamic_array[i].row)<='I')
                printf("\t\t     * Price = $300\n");
            else if (*(dynamic_array[i].row) == 'J')
                printf("\t\t     * Price = $500\n");
            printf("\t\t   *************************************\n\n");
        }
    }
    printf("\033[0m");
}

int main()
{
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
    char *booked_seat = "[X]";

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            strcpy(one.seats[i][j], empty_seat);
            strcpy(two.seats[i][j], empty_seat);
            strcpy(three.seats[i][j], empty_seat);
            strcpy(four.seats[i][j], empty_seat);
            strcpy(five.seats[i][j], empty_seat);
        }
    }

    dynamic_array = malloc(sizeof(Details));
       if (dynamic_array == NULL)
       {
           printf("Memory allocation failed!\n");
       }

       int flag = 0;
       while (flag != 1)
       {
           PrintMenu();
           int n;
           scanf("%d", &n);
           switch (n)
           {
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

       free(dynamic_array);
       return 0;

}
