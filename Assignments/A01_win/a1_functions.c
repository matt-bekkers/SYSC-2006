/********* a1_functions.c ********
	
	Student Name 	= Matthé Bekkers
	Student Number	= 101297066
*/

#include <stdio.h>
#include <stdlib.h>

unsigned short int get_imput_usi(void) {
	unsigned short int result_usi;

	printf("Please enter a value: ");
	result_usi = scanf("%hu", &result_usi);

	while (result_usi < 0) {
		printf("Please enter a value over zero: ");
		scanf("%hu", &result_usi);
	}
	return result_usi;
}

float get_input_f(void) {
	float result_f;

	printf("Please enter a value: ");
	result_f = scanf("%hu", &result_f);

	while (result_f < 0) {
		printf("Please enter a value over zero: ");
		scanf("%hu", &result_f);
	}
	return result_f;
}

