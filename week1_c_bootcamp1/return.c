#include<stdio.h>
#include<string.h>
int main(){
    char name[6]="Hello";
    char reverse[99];
    printf("%s\n",name);
    for(int i = 4 ;i>=0;--i){
        reverse[4-i]=name[i];
    }
    printf("%s\n",reverse);
}