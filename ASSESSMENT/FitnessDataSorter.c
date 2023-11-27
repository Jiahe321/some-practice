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
        tokeniseRecord(line,',',data[*count].date,data[*count].time,&data[*count].steps);
        if (strstr(data[*count].date,"-")==NULL||strstr(data[*count].time,":")==NULL||data[*count].steps==0) {
            // Handle the case when tokeniseRecord returns an error
            puts("Error: Invalid data format in the file.");
            fclose(fp);
            return 1;
        }
        ++(*count);
    }
    fclose(fp);
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
        data[j+1] = temp;
    }
}

int output_tsv(char filename[], FitnessData data[],int count){
    FILE *fp=fopen(filename, "w");
    if(fp==NULL){
        printf("Error: Could not find or open the file.");
        return 1;
    }
    for(int i=0;i<count;++i){
        fprintf(fp,"%s\t%s\t%d\n",data[i].date,data[i].time,data[i].steps);
    }
    printf("Data sorted and written to %s\n", filename);
    fclose(fp);
    return 0;
}

int main(){
    FitnessData data[100];
    int count=0;
    char filename[100];
    int f=1;
    printf("Enter Filename:");
    scanf("%s",filename);
    if(import_file(filename,data,&count)){
        return 1;
    }
    //change the .csv into .tsv
    strcat(filename,".tsv");
    sort(data,count);
    output_tsv(filename,data,count);
    return 0;
}
