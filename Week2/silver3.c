#include<stdio.h>
int main(){
    int score;
    puts("Please input the score:");
    scanf("%d",&score);
    if(score>=0&&score<=100){
        if(score>=70) puts("Distinction!");
        else if(score>=50) puts("Pass!");
        else puts("Failed!");
    }
    else puts("invalid score.");
    return 0;
}