#include<stdio.h>
int main(){
    int score;
    printf("input the score: ");
    scanf("%d",&score);
    if(score>=40) puts("pass");
    else puts("fail");
}