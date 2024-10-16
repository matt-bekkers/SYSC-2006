/********* a1_functions.c ********
	
	Student Name 	= Matthé Bekkers
	Student Number	= 101297066
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "a1_data_structures.h"

unsigned short int get_input_usi(void) {
	unsigned short int result_usi;

	printf("Please enter a value: ");
	scanf("%hu", &result_usi);

	while (result_usi < 0 || result_usi > 5) {
		printf("Please enter a value over zero: ");
		scanf("%hu", &result_usi);
	}
	return result_usi;
}

float get_input_f(void) {
	float result_f;

	printf("Please enter a value: ");
	scanf("%hu", &result_f);

	while (result_f < 0) {
		printf("Please enter a value over zero: ");
		scanf("%hu", &result_f);
	}
	return result_f;
}

// Function to initialize an activity via a struct
void init_activity(activity_t * activity_to_int) {
	unsigned short int id;
	char name[100];
	float planned_cost;
	float actual_cost = 0.0;
	unsigned short int planned_duration;
	unsigned short int actual_duration = 0;
	_Bool completed = false;

	printf("* Welcome to the activity initialisation screen!\nPlease input the activity ID: ");
	scanf("%hu", &id);
	printf("You selected %hu as the activity ID.\n", id);
	printf("\nPlease input the activity name: ");
	scanf("%s", &name);
	printf("\nPlease input the planned duration of the activity: ");
	scanf("%hu", &planned_duration);
	planned_cost = planned_duration * 30;
	printf("\nPlanned cost has been calculated to %.2f.\n", planned_cost);


	activity_to_int->id = id;
	strcpy(activity_to_int->name, name);
	activity_to_int->planned_cost = planned_cost;
	activity_to_int->actual_cost = actual_cost;
	activity_to_int->planned_duration = planned_duration;
	activity_to_int->actual_duration = actual_duration;
	activity_to_int->completed = completed;

}

void init_milestone(milestone_t * milestone_to_int, unsigned short int number_activities) {
	int id;
	char name[100];
	_Bool completed = false;
	unsigned short int actual_cost = 0;
	unsigned short int actual_duration = 0;

	printf("Please enter your milestone name: ");
	scanf("%s", &name);
	printf("Starting the activity initialisation process for this milestone...\n");

	for (int i = 0; i < number_activities; i++) {
		printf("Initializing activity %d.\n", i + 1);
		init_activity(&milestone_to_int->activity_list[i]);
	}

	milestone_to_int->id = id;
	strcpy(milestone_to_int->name, name);
	milestone_to_int->completed = completed;
	milestone_to_int->actual_cost = actual_cost;
	milestone_to_int->actual_duration = actual_duration;

}

project_t init_project(char name[], milestone_t *milestone_list, int number_milestones, const int * number_activities) {
	
}

void print_main_menu(void) {
	unsigned short int choice;

	printf("Main menu. Please select an option.\n1. Update activity\n2. Print stats\n3. Exit\n");
	scanf("%hu", &choice);
	while (choice < 1 || choice > 3) {
		printf("Please enter a valid choice. Valid choices include:\n1. Update activity\n2. Print stats\n3. Exit\n");
		scanf("%hu", &choice);
	}
}

/*
_Bool dupe_id(int id, milestone_t *milestone_arr, int number_of_milestones) {
	for (int i = 0; i < number_of_milestones; i++) {
		if (*(milestone_arr).id() == id) {
			return false;
		}
	}
}*/