/********* main.c ********
	
	Student Name 	= Matthé Bekkers
	Student Number	= 101297066
*/

//Complete the includes
#include <stdlib.h>
#include <stdio.h>

#include "a1_functions.h"

int main()
{

    /** 1-  Display a welcome message **/
    
    printf("*-----------------------------------------------------*\n");
    printf("*            Welcome to the scheduler tool!           *\n");
    printf("*-----------------------------------------------------*\n");
    printf("                                                       \n");

    /** 2- Get the project's name and number of milestones **/
    char project_name[255];
    int number_milestones;

    printf("*-----------------------------------------------------*\n");
    printf("*                    Main Menu                        *\n");
    printf("*-----------------------------------------------------*\n");
    printf("                                                       \n");
    printf("* Please enter the project name: ");
    scanf("%s", &project_name);
    printf("* You selected '%s' as your project.\n", project_name);
    printf("*\n");
    printf("* Select your number of milestones below.\n");
    number_milestones = get_input_usi();
    printf("*  You selected '%d' as your number of milestones.\n", number_milestones);


    /** 3- Initialize all milestones and activities.
     * You need an array of milestones. 
     * The capacity of the array must be the max number of milestones the program 
     * can handle as per the instructions **/

    int milestones[5];

    
    
    /** 4- Initialize the project **/
    

    /** 5- Print the main menu **/

   

    /** 6- Get user choice and handle it as per the instructions**/
    
    return EXIT_SUCCESS;
}