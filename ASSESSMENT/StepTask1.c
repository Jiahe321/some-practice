#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



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

// Complete the main function
int main() {
    FILE *fp=fopen("FitnessData_2023.csv","r");
    // Make sure that we can open the file.
    if(fp==NULL){
        perror("");
        return 1;
    }
    // This is where we store the data.
    FITNESS_DATA data[100];
    // Count the number of records by num.
    int num=0;
    // Store data temporary.
    char str[100], step[15];
    // Scane the file until the end.
    while(fgets(str,sizeof(str),fp)!=NULL){
        // The delimiter is ","
        tokeniseRecord(str,",",data[num].date,data[num].time,step);
        // Change the char output into integer.
        data[num].steps= atoi(step);
        ++num;
    }
    // Print the number.
    printf("Number of records in file: %d\n",num);
    // Print the file.
    for(int i=0;i<num;++i){
        printf("%s/%s/%d\n",data[i].date,data[i].time,data[i].steps);
    }
    fclose(fp);
    return 0;
}


