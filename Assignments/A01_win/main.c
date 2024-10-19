/********* main.c ********
	
	Student Name 	= Matthé Bekkers
	Student Number	= 101297066
*/

//Complete the includes
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "a1_functions.h"
//#include "a1_data_structures.h"

int main()
{
    char project_name[255];
    unsigned short int number_milestones, actual_project_duration;
    float planned_project_duration = 0;
    float planned_project_cost = 0;
    _Bool project_completed = 0;

    /** 1-  Display a welcome message **/
    
    printf("*-----------------------------------------------------*\n");
    printf("*            Welcome to the scheduler tool!           *\n");
    printf("*-----------------------------------------------------*\n");
    printf("                                                       \n");

    /** 2- Get the project's name and number of milestones **/

    printf("*-----------------------------------------------------*\n");
    printf("*                    Main Menu                        *\n");
    printf("*-----------------------------------------------------*\n");
    printf("                                                       \n");
    printf("* Please enter the project name: ");
    scanf("%s", &project_name);
    printf("* You selected '%s' as your project.\n", project_name);
    printf("* Select your number of milestones below.\n");
    number_milestones = get_input_usi();
    while (number_milestones < 1 || number_milestones > 5) {
        printf("Please select a value between 1 and 5: ");
        scanf("%hu", &number_milestones);
    }
    printf("*  You selected '%d' as your number of milestones.\n", number_milestones);


    /** 3- Initialize all milestones and activities.
     * You need an array of milestones. 
     * The capacity of the array must be the max number of milestones the program 
     * can handle as per the instructions **/

    milestone_t milestone_arr[5];
    //activity_t activity_arr[5][3];

    
    
    printf("Project initialisation sucessful. Loading into main menu...\n");
    
    /** 4- Initialize the project **/

    project_t project = init_project(project_name, milestone_arr, number_milestones, NUM_ACTIVITIES);
    
    // Calculate project cost & project duration
    for (int i = 0; i < number_milestones; i++) {
        for (int j = 0; j < NUM_ACTIVITIES; j++) {
            printf("Milestone %hu, activity %d cost: %.f\n", i + 1, j + 1, milestone_arr[i].activity_list[j].planned_cost);
            planned_project_cost += milestone_arr[i].activity_list[j].planned_cost;
            planned_project_duration += milestone_arr[i].activity_list[j].planned_duration;
        }
    }

    planned_project_duration = (int) (ceil(planned_project_duration / 8));

    printf("The total planned cost for the project is %.f$.\n", planned_project_cost);
    printf("The total planned duration for the project is %d.\n", planned_project_duration);

    project.planned_cost = planned_project_cost;
    project.planned_duration = planned_project_duration;

    /** 5- Print the main menu **/
    print_main_menu();

    /** 6- Get user choice and handle it as per the instructions**/
    unsigned short int choice;

    printf("Main menu: \n1. Print sub-menu\n2. Print projects stats\n3. Exit\n");
    choice = get_input_usi();
    while (choice < 1 || choice > 3) {
        printf("Please select a choice within 1 and 3: ");
        scanf("%hu", &choice);
    }


    
    return EXIT_SUCCESS;
}