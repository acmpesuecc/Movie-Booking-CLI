#include<stdio.h>
#include "bill_handler.h"
#include "movie_book.h"

typedef struct {
    char name[50];
    char email[50];
    char mobile[10];
    char movie_selected[50];
} Details;

Details *dynamic_array = NULL;
int count = 0;


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