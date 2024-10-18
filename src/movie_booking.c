#include <stdio.h>
#include "movie_booking.h"
#include "movie_book.h"

Theatre *list = NULL;

Details *dynamic_array = NULL;
int count = 0;

Theatre one, two, three, four, five;

void Book()
{
    printf("   >>> Enter your first or last name: ");
    char search[50];
    scanf("%s", search);
    for (int i = 0; i < count; i++)
    {
        if (strstr(dynamic_array[i].name, search) != NULL)
        {
            printf("   Which Movie would you like to watch:\n");
            printf("   \t(1) Dune 2\n");
            printf("   \t(2) Transformers One\n");
            printf("   \t(3) Oppenheimer\n");
            printf("   \t(4) Inception\n");
            printf("   \t(5) Tenet\n");
            printf("   >>>");
            int n;
            scanf("%d", &n);
            char movie_chosen[50];
            int movie_num;
            switch(n)
            {
                case 1:
                    strcpy(movie_chosen,"Dune 2");
                    movie_num = 1;
                    break;
                case 2:
                    strcpy(movie_chosen,"Transformers One");
                    movie_num = 2;
                    break;
                case 3:
                    strcpy(movie_chosen,"Oppenheimer");
                    movie_num = 3;
                    break;
                case 4:
                    strcpy(movie_chosen,"Inception");
                    movie_num = 4;
                    break;
                case 5:
                    strcpy(movie_chosen,"Tenet");
                    movie_num = 5;
                    break;
                default:
                    printf("Invalid");
                    break;
            }
            switch (movie_num){
                case 1:
                    ReadCSVAndUpdateSeats("data.csv",&one,movie_chosen);
                    break;
                case 2:
                    ReadCSVAndUpdateSeats("data.csv",&two,movie_chosen);
                    break;
                case 3:
                    ReadCSVAndUpdateSeats("data.csv",&three,movie_chosen);
                    break;
                case 4:
                    ReadCSVAndUpdateSeats("data.csv",&four,movie_chosen);
                    break;
                case 5:
                    ReadCSVAndUpdateSeats("data.csv",&five,movie_chosen);
                    break;
                default:
                    break;
            }
            char s;
            char *empty_seat = "[ ]";
            char *booked_seat = "[X]";
            if (n == 1)
                {
                    strcpy(dynamic_array[i].movie_selected, "Dune 2");
                    printf("   You have chosen the movie Dune 2\n");
                    printf("   Select a Seat!\n");

                    printf("\t\tRecliner $500\n");
                    for (int i = 9; i > 8; i--)
                    {
                        printf("\033[38;5;250m");
                        printf("\t\t%c ",'A'+i);
                        printf("\033[0m");
                        for (int j = 0; j < 15; j++)
                        {
                            if (strcmp(one.seats[i][j], empty_seat) == 0)
                                printf("\033[1;32m");
                            else
                                printf("\033[1;31m");
                            printf("%s ", one.seats[i][j]);
                        }
                        printf("\033[0m");
                        printf("\n");
                    }
                    printf("\t\tPrime $300\n");
                    for (int i = 8; i > 5; i--)
                    {
                        printf("\033[38;5;250m");
                        printf("\t\t%c ",'A'+i);
                        printf("\033[0m");
                        for (int j = 0; j < 15; j++)
                        {
                            if (strcmp(one.seats[i][j], empty_seat) == 0)
                                printf("\033[1;32m");
                            else
                                printf("\033[1;31m");
                            printf("%s ", one.seats[i][j]);
                        }
                        printf("\033[0m");
                        printf("\n");
                    }
                    printf("\t\tNomral $200\n");
                    for (int i = 5; i >= 0; i--)
                    {
                        printf("\033[38;5;250m");
                        printf("\t\t%c ",'A'+i);
                        printf("\033[0m");
                        for (int j = 0; j < 15; j++)
                        {
                            if (strcmp(one.seats[i][j], empty_seat) == 0)
                                printf("\033[1;32m");
                            else
                                printf("\033[1;31m");
                            printf("%s ", one.seats[i][j]);
                        }
                        printf("\033[0m");
                        printf("\n");
                    }
                    printf("\t\t   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15\n\n");
                    printf("   >>> Enter the row you would like: ");
                    scanf(" %c", &s);
                    printf("   >>> Enter the seat number you would like (1-15)");
                    int num;
                    scanf("%d", &num);

                    int temp = s - 'A';
                    strcpy(one.seats[temp][num - 1], booked_seat);

                    dynamic_array[i].row = malloc(sizeof(char));
                    *(dynamic_array[i].row) = s;
                    dynamic_array[i].col = num;
                }
            if (n == 2)
                {
                    strcpy(dynamic_array[i].movie_selected, "Transformers One");
                    printf("   You have chosen the movie Transformers One\n");
                    printf("   Select a Seat!\n");

                    printf("\t\tRecliner $500\n");
                    for (int i = 9; i > 8; i--)
                    {
                        printf("\033[38;5;250m");
                        printf("\t\t%c ",'A'+i);
                        printf("\033[0m");
                        for (int j = 0; j < 15; j++)
                        {
                            if (strcmp(two.seats[i][j], empty_seat) == 0)
                                printf("\033[1;32m");
                            else
                                printf("\033[1;31m");
                            printf("%s ", two.seats[i][j]);
                        }
                        printf("\033[0m");
                        printf("\n");
                    }
                    printf("\t\tPrime $300\n");
                    for (int i = 8; i > 5; i--)
                    {
                        printf("\033[38;5;250m");
                        printf("\t\t%c ",'A'+i);
                        printf("\033[0m");
                        for (int j = 0; j < 15; j++)
                        {
                            if (strcmp(two.seats[i][j], empty_seat) == 0)
                                printf("\033[1;32m");
                            else
                                printf("\033[1;31m");
                            printf("%s ", two.seats[i][j]);
                        }
                        printf("\033[0m");
                        printf("\n");
                    }
                    printf("\t\tNomral $200\n");
                    for (int i = 5; i >= 0; i--)
                    {
                        printf("\033[38;5;250m");
                        printf("\t\t%c ",'A'+i);
                        printf("\033[0m");
                        for (int j = 0; j < 15; j++)
                        {
                            if (strcmp(two.seats[i][j], empty_seat) == 0)
                                printf("\033[1;32m");
                            else
                                printf("\033[1;31m");
                            printf("%s ", two.seats[i][j]);
                        }
                        printf("\033[0m");
                        printf("\n");
                    }
                    printf("\t\t   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15\n\n");

                    printf("   >>> Enter the row you would like: ");
                    scanf(" %c", &s);
                    printf("   >>> Enter the seat number you would like (1-15)");
                    int num;
                    scanf("%d", &num);

                    int temp = s - 'A';
                    strcpy(two.seats[temp][num - 1], booked_seat);

                    dynamic_array[i].row = malloc(sizeof(char));
                    *(dynamic_array[i].row) = s;
                    dynamic_array[i].col = num;
                }
            if (n == 3)
                {
                    strcpy(dynamic_array[i].movie_selected, "Oppenheimer");
                    printf("   You have chosen the movie Oppenheimer\n");
                    printf("   Select a Seat!\n");

                    printf("\t\tRecliner $500\n");
                    for (int i = 9; i > 8; i--)
                    {
                        printf("\033[38;5;250m");
                        printf("\t\t%c ",'A'+i);
                        printf("\033[0m");
                        for (int j = 0; j < 15; j++)
                        {
                            if (strcmp(three.seats[i][j], empty_seat) == 0)
                                printf("\033[1;32m");
                            else
                                printf("\033[1;31m");
                            printf("%s ", three.seats[i][j]);
                        }
                        printf("\033[0m");
                        printf("\n");
                    }
                    printf("\t\tPrime $300\n");
                    for (int i = 8; i > 5; i--)
                    {
                        printf("\033[38;5;250m");
                        printf("\t\t%c ",'A'+i);
                        printf("\033[0m");
                        for (int j = 0; j < 15; j++)
                        {
                            if (strcmp(three.seats[i][j], empty_seat) == 0)
                                printf("\033[1;32m");
                            else
                                printf("\033[1;31m");
                            printf("%s ", three.seats[i][j]);
                        }
                        printf("\033[0m");
                        printf("\n");
                    }
                    printf("\t\tNomral $200\n");
                    for (int i = 5; i >= 0; i--)
                    {
                        printf("\033[38;5;250m");
                        printf("\t\t%c ",'A'+i);
                        printf("\033[0m");
                        for (int j = 0; j < 15; j++)
                        {
                            if (strcmp(three.seats[i][j], empty_seat) == 0)
                                printf("\033[1;32m");
                            else
                                printf("\033[1;31m");
                            printf("%s ", three.seats[i][j]);
                        }
                        printf("\033[0m");
                        printf("\n");
                    }
                    printf("\t\t   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15\n\n");

                    printf("   >>> Enter the row you would like: ");
                    scanf(" %c", &s);
                    printf("   >>> Enter the seat number you would like (1-15)");
                    int num;
                    scanf("%d", &num);

                    int temp = s - 'A';
                    strcpy(three.seats[temp][num - 1], booked_seat);

                    dynamic_array[i].row = malloc(sizeof(char));
                    *(dynamic_array[i].row) = s;
                    dynamic_array[i].col = num;
                }
            if (n == 4)
                {
                    strcpy(dynamic_array[i].movie_selected, "Inception");
                    printf("   You have chosen the movie Inception\n");
                    printf("   Select a Seat!\n");

                    printf("\t\tRecliner $500\n");
                    for (int i = 9; i > 8; i--)
                    {
                        printf("\033[38;5;250m");
                        printf("\t\t%c ",'A'+i);
                        printf("\033[0m");
                        for (int j = 0; j < 15; j++)
                        {
                            if (strcmp(four.seats[i][j], empty_seat) == 0)
                                printf("\033[1;32m");
                            else
                                printf("\033[1;31m");
                            printf("%s ", four.seats[i][j]);
                        }
                        printf("\033[0m");
                        printf("\n");
                    }
                    printf("\t\tPrime $300\n");
                    for (int i = 8; i > 5; i--)
                    {
                        printf("\033[38;5;250m");
                        printf("\t\t%c ",'A'+i);
                        printf("\033[0m");
                        for (int j = 0; j < 15; j++)
                        {
                            if (strcmp(four.seats[i][j], empty_seat) == 0)
                                printf("\033[1;32m");
                            else
                                printf("\033[1;31m");
                            printf("%s ", four.seats[i][j]);
                        }
                        printf("\033[0m");
                        printf("\n");
                    }
                    printf("\t\tNomral $200\n");
                    for (int i = 5; i >= 0; i--)
                    {
                        printf("\033[38;5;250m");
                        printf("\t\t%c ",'A'+i);
                        printf("\033[0m");
                        for (int j = 0; j < 15; j++)
                        {
                            if (strcmp(four.seats[i][j], empty_seat) == 0)
                                printf("\033[1;32m");
                            else
                                printf("\033[1;31m");
                            printf("%s ", four.seats[i][j]);
                        }
                        printf("\033[0m");
                        printf("\n");
                    }
                    printf("\t\t   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15\n\n");

                    printf("   >>> Enter the row you would like: ");
                    scanf(" %c", &s);
                    printf("   >>> Enter the seat number you would like (1-15)");
                    int num;
                    scanf("%d", &num);

                    int temp = s - 'A';
                    strcpy(four.seats[temp][num - 1], booked_seat);

                    dynamic_array[i].row = malloc(sizeof(char));
                    *(dynamic_array[i].row) = s;
                    dynamic_array[i].col = num;
                }
            if (n == 5)
                {
                    strcpy(dynamic_array[i].movie_selected, "Tenet");
                    printf("   You have chosen the movie Tenet\n");
                    printf("   Select a Seat!\n");

                    printf("\t\tRecliner $500\n");
                    for (int i = 9; i > 8; i--)
                    {
                        printf("\033[38;5;250m");
                        printf("\t\t%c ",'A'+i);
                        printf("\033[0m");
                        for (int j = 0; j < 15; j++)
                        {
                            if (strcmp(five.seats[i][j], empty_seat) == 0)
                                printf("\033[1;32m");
                            else
                                printf("\033[1;31m");
                            printf("%s ", five.seats[i][j]);
                        }
                        printf("\033[0m");
                        printf("\n");
                    }
                    printf("\t\tPrime $300\n");
                    for (int i = 8; i > 5; i--)
                    {
                        printf("\033[38;5;250m");
                        printf("\t\t%c ",'A'+i);
                        printf("\033[0m");
                        for (int j = 0; j < 15; j++)
                        {
                            if (strcmp(five.seats[i][j], empty_seat) == 0)
                                printf("\033[1;32m");
                            else
                                printf("\033[1;31m");
                            printf("%s ", five.seats[i][j]);
                        }
                        printf("\033[0m");
                        printf("\n");
                    }
                    printf("\t\tNomral $200\n");
                    for (int i = 5; i >= 0; i--)
                    {
                        printf("\033[38;5;250m");
                        printf("\t\t%c ",'A'+i);
                        printf("\033[0m");
                        for (int j = 0; j < 15; j++)
                        {
                            if (strcmp(five.seats[i][j], empty_seat) == 0)
                                printf("\033[1;32m");
                            else
                                printf("\033[1;31m");
                            printf("%s ", five.seats[i][j]);
                        }
                        printf("\033[0m");
                        printf("\n");
                    }
                    printf("\t\t   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15\n\n");

                    printf("   >>> Enter the row you would like: ");
                    scanf(" %c", &s);
                    printf("   >>> Enter the seat number you would like (1-15)");
                    int num;
                    scanf("%d", &num);

                    int temp = s - 'A';
                    strcpy(five.seats[temp][num - 1], booked_seat);

                    dynamic_array[i].row = malloc(sizeof(char));
                    *(dynamic_array[i].row) = s;
                    dynamic_array[i].col = num;
                }
        }
    }
}
