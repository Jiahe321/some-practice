#include<stdio.h>
int main(){
    float a;
    puts("Please input a integer or float:");
    scanf("%f",&a);
    if(a>0) puts("The number is positive.");
    else if(a==0) puts("The number is zero");
    else puts("The number is negative.");
    return 0;
}