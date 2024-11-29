/*****************
    Student Name 	= Matthé Bekkers
    Student Number	= 101297066
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
    print_menu();
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
    strcpy(new_user->username, username);
    new_user->posts = NULL;
    new_user->friends = NULL;
    strcpy(new_user->password, password);
    user_t *traversal_ptr = users;
    if(traversal_ptr == NULL) {
        return new_user;
    }
    while(strcmp(new_user->username, traversal_ptr->username) == 0 && traversal_ptr->next != NULL) {
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
            return NULL;
        }
    }
    printf("User %s found.\n", username);
    return traversal_ptr;
}

post_t *create_post(const char *text) {
    post_t *new_post = malloc(sizeof(post_t));
    assert(new_post != NULL);
    strcpy(new_post->content, text);
    new_post->next = NULL;
    return new_post;
}

void add_post(user_t *user, const char *text) {
    post_t *post_to_be_added = create_post(text);
    post_to_be_added->next = user->posts;
    user->posts = post_to_be_added;
}

friend_t *create_friend(const char *username) {
    friend_t *new_friend = malloc(sizeof(friend_t));
    assert(new_friend != NULL);
    strcpy(new_friend->username, username);
    new_friend->next = NULL;
    return new_friend;
}

void add_friend(user_t *user, const char *friend) {

    friend_t *friend_to_be_added = create_friend(friend);
    assert(friend_to_be_added != NULL);
    user_t *current = user;
    assert(current->username != NULL);

    if(user->friends == NULL) {
        user->friends == friend_to_be_added;
        return;
    }
    
    while(current->next != NULL && friend_to_be_added != NULL && strcmp(friend_to_be_added->username, current->friends->username) != 0) {
        current = current->next;
    }

    friend_to_be_added->next = current->friends->next;
    current->friends->next = friend_to_be_added;
}

void display_all_user_posts(user_t *user) {
    post_t *current_post = user->posts;
    
    while(current_post != NULL) {
        printf("%s\n", user->posts->content);
        current_post = current_post->next;
        count++;
    }
}

_Bool delete_post(user_t *user) {
    user_t *head = user;
    user = user->next;
    free(head);
}

void display_posts_by_n(user_t *user, int number) {
    char choice_continue = "y";
    post_t *current_post = user->posts;

    while(choice_continue == "y") {
        for(int i = 0; i < number; i++) {
            if(current_post == NULL) {
                printf("No more posts to display");
                choice_continue = "n";
            }
            printf("%s\n", current_post->content);
            current_post = current_post->next;
        }

        printf("Do you wish do print the next three posts?: ");
        scanf("%c", choice_continue);
        
    }

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