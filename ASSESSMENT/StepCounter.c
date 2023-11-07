#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
int import_file(char filename[], FITNESS_DATA data[], int *count){
    FILE *fp=fopen(filename,"r");
    if (fp == NULL) {
        puts("Error: Could not find or open the file.");
        return 1;
    }
    char str[100], step[15];
    // Scane the file until the end.
    while(fgets(str,sizeof(str),fp)!=NULL){
        // The delimiter is ","
        tokeniseRecord(str,",",data[*count].date,data[*count].time,step);
        // Change the char output into integer.
        data[*count].steps=atoi(step);
        ++(*count);
    }
    fclose(fp);
    puts("File successfully loaded.");
    return 0;
}

void display_total_num(int *count){
    printf("Total records: %d\n",*count);
}

void fewest_steps(FITNESS_DATA data[], int *count){
    int min=32767,index=0;
    for(int i=0;i<*count;++i){
        if(data[i].steps<min){
            min=data[i].steps;
            index=i;
        }
    }
    printf("Fewest steps: %s %s\n",data[index].date,data[index].time);
}

void largest_steps(FITNESS_DATA data[], int *count){
    int max=-1,index=0;
    for(int i=0;i<*count;++i){
        if(data[i].steps>max){
            max=data[i].steps;
            index=i;
        }
    }
    printf("Largest steps: %s %s\n",data[index].date,data[index].time);
}

void mean(FITNESS_DATA data[], int *count){
    int sum=0;
    for(int i=0;i<*count;++i) sum+=data[i].steps;
    printf("Mean step count: %d\n",sum/(*count));
}

void above500(FITNESS_DATA data[], int *count){
    int start=0,end=0,len=0;
    for(int i=0;i<*count;++i){
        // counting when steps more than 500
        if(data[i].steps>500) len++;
        // end counting.
        else if(len){
            // update the longest one
            if(len > end-start){
                end=i-1;
                start=i-len;
            }
            len=0;
        }
    }
    // the last item
    if(len>end-start){
            end=*count-1;
            start=end-len;
    }
    printf("Longest period start: %s %s\n", data[start].date, data[start].time);
    printf("Longest period end: %s %s\n", data[end].date, data[end].time);
}

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
        scanf("%c",&option);
        getchar();// get rid of extra "\n"
        // I based this on a discussion with ChatGPT
        // When I input an available option
        // It says that the option unavailable
        // I cannot understand why until I use ChatGPT
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
