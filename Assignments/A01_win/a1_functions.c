/********* a1_functions.c ********
	
	Student Name 	= Matthé Bekkers
	Student Number	= 101297066
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to initialize and activity via a struct
void init_activity(activity_t * activity_to_int) {
	unsigned short int id;
	char name[100];
	float planned_cost;
	float actual_cost = 0.0;
	unsigned short int planned_duration;
	unsigned short int actual_duration = 0;
	_Bool completed = false;

	printf("Please input the activity ID: ");
	scanf("%s", &id);
	while ()
}

void init_milestone(milestone_t * milestone_to_int, unsigned short int number_activities) {
	int id;
	char name[100];
	
}

_Bool dupe_id(int id) {
	for 
}