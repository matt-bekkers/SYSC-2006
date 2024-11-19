/*****************
    Student Name 	=
    Student Number	=
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include "a2_nodes.h"
#include "a2_functions.h"

// Your solution goes here

void print_menu() {
    printf("***********************************************\n");
    printf("                MAIN MENU:\n");
    printf("***********************************************\n");
    printf("1. Register a new user\n");
    printf("2. Manage a user's profile (change password)\n");
    printf("3. Manage a user's posts (add/remove)\n");
    printf("4. Manage a user's friends (add/remove)\n");
    printf("5. Display a user's posts\n");
    printf("6. Exit\n\n");
    printf("Enter your choice: ");
}

int menu_choice() {
    int choice;
    scanf("%d", &choice);
    while(choice < 1 || choice > 6) {
        printf("Invalid choice. Please try again: ");
        scanf("%d", choice);
    }

    return choice;
}

user_t *add_user(user_t *users, const char *username, const char *password) {
    user_t *new_user = malloc(sizeof(user_t));
    assert(new_user != NULL);
    user_t *traversal_ptr = users;
    strcpy(new_user->username, username);
    strcpy(new_user->username, username);
    while(strcmp(new_user->username, traversal_ptr->username) > 0) {
        traversal_ptr = traversal_ptr->next;
    }
    new_user->next = traversal_ptr->next;
    traversal_ptr->next = new_user;

    return users;
}

user_t *find_user(user_t *users, const char *username) {
    user_t *traversal_ptr = users;
    while(strcmp(traversal_ptr->username, username) != 0) {
        traversal_ptr = traversal_ptr->next;
        if(traversal_ptr == NULL) {
            printf("ERROR: User not found.\n");
            return;
        }
    }
    printf("User %s found.\n", username);
    return traversal_ptr;
}

/*
   ******** DONT MODIFY THIS FUNCTION ********
   Function that reads users from the text file.
   IMPORTANT: This function shouldn't be modified and used as is
   ******** DONT MODIFY THIS FUNCTION ********
*/
user_t *read_CSV_and_create_users(FILE *file, int num_users)
{
    srand(time(NULL));
    user_t *users = NULL;
    char buffer[500];
    fgets(buffer, sizeof(buffer), file); // Read and discard the header line
    int count = 0;
    for (int i = 0; i < num_users; i++)
    {
        fgets(buffer, sizeof(buffer), file);
        buffer[strcspn(buffer, "\r\n")] = 0; // Remove newline characters

        char *token = strtok(buffer, ",");
        char *token2 = strtok(NULL, ",");
        users = add_user(users, token, token2);
        char *username = token;

        token = strtok(NULL, ",");

        user_t *current_user = users;
        for (; current_user != NULL && strcmp(current_user->username, username) != 0; current_user = current_user->next)
            ;

        while (token != NULL && strcmp(token, ",") != 0 && count < 3)
        {
            if (strcmp(token, " ") != 0)
            {
                add_friend(current_user, token);
            }
            token = strtok(NULL, ",");
            count++;
        }
        count = 0;

        // token = strtok(NULL, ",");
        while (token != NULL && strcmp(token, ",") != 0)
        {
            add_post(current_user, token);
            token = strtok(NULL, ",");
        }
    }
    return users;
}