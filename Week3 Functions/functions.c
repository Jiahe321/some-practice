#include<stdio.h>
int main(){
    int y=2;
    int sum(int a, int b);
    int z = sum(5,y);
    printf("%d\n",z);
}
int sum(int a, int b){
    return a+b;
}