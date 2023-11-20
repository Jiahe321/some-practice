#include<stdio.h>
typedef struct{
    char date[20];
    float bloodIron;
} reading;
reading today,thisWeek[7];
int main(){
    puts("Enter a single 'reading' object:");
    scanf("%s %f",today.date,&today.bloodIron);
    printf("%s %f",today.date,today.bloodIron);
}