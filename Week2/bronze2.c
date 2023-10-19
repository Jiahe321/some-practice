#include<stdio.h>
int main(){
    int a;
    puts("Please input a integer:");
    scanf("%d",&a);
    if(a/4 == a/4.0 && a/5 == a/5.0) puts("The number is divisible by both 4 and 5.");
    else puts("The number is not divisible by both 4 and 5.");
    return 0;
}