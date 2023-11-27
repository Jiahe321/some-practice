#include<stdio.h>
#include<string.h>
#include <stdlib.h>
struct data{
    char date[60];
    float value;
}lines[300];

void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, float *bloodIron)
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);

    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL)
    {
        strcpy(date, token);
    }

    token = strtok(NULL, delimiter);
    if (token != NULL)
    {
        // turns the blood iron into a float - similar to atoi().
        // we have to tell C that bloodIron is a pointer so it stores it.
        *bloodIron = atof(token);
    }

    // Free the duplicated string
    free(inputCopy);
}
int main(){
    FILE *fp=fopen("data.txt","r");
    if (fp == NULL) {
        puts("Error: Could not find or open the file.");
        return 1;
    }
    char line[100], date[15];
    int count=0;
    while(fgets(line,sizeof(line),fp)!=NULL){
        tokeniseRecord(line,',',lines[count].date,&lines[count].value);
        ++count;
    }
    fclose(fp);
}