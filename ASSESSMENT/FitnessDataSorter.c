#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

int import_file(char filename[], FitnessData data[], int *count){
    FILE *fp=fopen(filename,"r");
    if (fp == NULL) {
        puts("Error: Could not find or open the file.");
        return 1;
    }
    char line[100], step[15];
    // Scane the file until the end.
    while(fgets(line,sizeof(line),fp)!=NULL){
        // The delimiter is ","
        tokeniseRecord(line,',',data[*count].date,data[*count].time,data[*count].steps);
        // Change the char output into integer.
        ++(*count);
    }
    fclose(fp);
    puts("File successfully loaded.");
    return 0;
}

void sort(FitnessData data[],int count){
    FitnessData temp;
    int j;
    for(int i=1;i<count;++i){
        temp = data[i];
        j=i-1;
        while(j>=0&&(data[j].steps<temp.steps)){
            data[j+1]=data[j];
            --j;
        }
        data[j + 1] = temp;
    }
}

void output_tsv(char filename[], FitnessData data[],int count){
    FILE *fp=fopen(filename, "w");
    if(fp==NULL){
        printf("Error: Could not find or open the file.");
        return 1;
    }
    for(int i=0;i<count;++i){
        fprintf("%s\t%s\t%d\t",data[i].date,data[i].steps,data[i].time);
    }
    printf("Data sorted and written to %s\n", filename);
    fclose(fp);
}

int main(){
    FitnessData data[100];
    int count=0;
    char filename[100];
    int f=1;
    puts("Enter Filename:");
    scanf("%s",filename);
    // Try until get the correct filename(return 0)
    while(import_file(filename,data,&count)){
        puts("Enter Filename:");
        scanf("%s",filename);
    }
    printf("Enter Filename: %s\n", filename);
    //change the .csv into .tsv
    for(int i=0;i<len(filename);++i){
        if(filename[i]=='.'){
            filename[i+1]='t';
            break;
        }
    }
    sort(data,count);
    output_tsv(filename,data,count);
}
