// Use our document.
#include "FitnessDataStruct.h"

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

int import_file(char filename[], FITNESS_DATA data[], int *count){
    FILE *fp=fopen(filename,"r");
    if (fp == NULL) {
        perror("Unable to open the file.");
        return 1;
    }
    char str[100], step[15];
    // Scane the file until the end.
    while(fgets(str,sizeof(str),fp)!=NULL){
        // The delimiter is ","
        tokeniseRecord(str,",",data[*count].date,data[*count].time,step);
        // Change the char output into integer.
        data[*count].steps= atoi(step);
        ++(*count);
    }
    fclose(fp);
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
    int start=0,end=0,len=0,f=0;
    for(int i=0;i<*count;++i){
        if(data[i].steps>=500){
            // start counting
            if(!f) f=1;
            // continue counting
            len++;
        }
        // end counting.
        else if(f){
            // update the longest one
            if(len > end-start){
                end=i-1;
                start=i-len;
            }
            len=0;
            f=0;
        }
    }
    // the last item
    if(f&&len>end-start){
            end=*count-1;
            start=end-len;
    }
    printf("Longest period start: %s %s\n", data[start].date, data[start].time);
    printf("Longest period end: %s %s\n", data[end].date, data[end].time);
}

int main(){
    FITNESS_DATA data[100];
    int count=0;
    char fname[100];
    int f=1;
    while(f){
        puts("A: Input filename");
        puts("B: Total records");
        puts("C: Fewest steps");
        puts("D: Largest steps");
        puts("E: Mean step count");
        puts("F: Longest period");
        puts("Q: Quit");
        puts("");
        char option;
        scanf("%c",&option);
        getchar();// get rid of extra "\n"
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
        default:puts("Please enter the correct choice!");
        }
        puts("");
    }
}
