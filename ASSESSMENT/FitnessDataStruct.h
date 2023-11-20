#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);
int import_file(char filename[], FITNESS_DATA data[], int *count){
    FILE *fp=fopen(filename,"r");
    if (fp == NULL) {
        puts("Error: Could not find or open the file.");
        return 1;
    }
    char str[100], step[15];
    // Scane the file until the end.
    *count = 0;
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
    printf("Mean step count: %d\n",(int)((sum*1.0 / *count)+0.5));
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


#endif // FITNESS_DATA_STRUCT_H