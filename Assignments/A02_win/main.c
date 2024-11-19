/********* main.c ********
    Student Name 	=
    Student Number	=
*/

// Includes go here
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "a2_nodes.h"
#include "a2_functions.h"

int main()
{
    FILE *csv_file = fopen("user_details.csv", "r");
    if (csv_file == NULL)
    {
        perror("Error opening the CSV file");
        return 1;
    }
    // Parse CSV data and create users
    user_t *users = read_CSV_and_create_users(csv_file, 50);

    fclose(csv_file);
 
    print_menu();

    int choice = menu_choice();
    while(choice != 6){
        switch (choice){
        case 1:
            char username[30];
            char password[30];
            printf("Please enter a username: ");
            scanf("%s", &username);
            printf("Please enter a password: ");
            scanf("%s", &password);
            add_user();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            printf("Exiting...\n");
            break;
        }
    }

}