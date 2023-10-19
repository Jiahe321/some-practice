#include<stdio.h>
int main(){
    int x;
    puts("input a integer: ");
    scanf("%d",&x);
    while(x!=-1){
        if(x>=0&&x<=100){
            puts("In the range of 0 to 100!");
        }
        else puts("Not in the range of 0 to 100!");
        puts("input a integer: ");
        scanf("%d",&x);
    }
    puts("Input is -1. Program end.");
}