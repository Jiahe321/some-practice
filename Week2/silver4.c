#include<stdio.h>
int main(){
    int a;
    puts("Please input the tempreture:");
    scanf("%d",&a);
    if(a>=-10 && a<=40) puts("In the range.");
    else puts("Not in the range.");
    return 0;
}