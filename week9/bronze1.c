#include<stdio.h>
#include<string.h>
int main(){
    char str[20];
    puts("Input a string:");
    scanf("%s",str);
    int lenth=strlen(str);
    char str2[lenth+1];
    strcpy(str2,str);
    printf("%s\n",str2);
}