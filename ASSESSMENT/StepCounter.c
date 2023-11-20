#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

int main(){
    FITNESS_DATA data[100];
    int count=0;
    char fname[100];
    int f=1;
    while(f){
        puts("Menu Options:");
        puts("A: Specify the filename to be imported");
        puts("B: Display the total number of records in the file");
        puts("C: Find the date and time of the timeslot with the fewest steps");
        puts("D: Find the date and time of the timeslot with the largest number of steps");
        puts("E: Find the mean step count of all the records in the file");
        puts("F: Find the longest continuous period where the step count is above 500 steps");
        puts("Q: Quit");
        printf("Enter choice: ");
        char option;
        option=getchar();
        getchar();
        switch(option){
        case 'A':
            printf("Input filename: ");
            scanf("%s", fname);
            getchar();// get rid of extra "\n"
            import_file(fname, data, &count);
            break;
        case 'B':
            display_total_num(&count);
            break;
        case 'C':
            fewest_steps(data, &count);
            break;
        case 'D':
            largest_steps(data, &count);
            break;
        case 'E':
            mean(data, &count);
            break;
        case 'F':
            above500(data, &count);
            break;
        case 'Q':
            f=0;
            break;
        default:puts("Invalid choice. Try again.");
        }
    }
}
