#include<stdio.h>
int main(){
    int a=0;
    while(1){
        printf("a is equal to %d\n",a);
        a++;
        if(a==5) break;
    }
    printf("Loop ended. And a is equal to: %d",a);
}