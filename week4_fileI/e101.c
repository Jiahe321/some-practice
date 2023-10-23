#include<stdio.h>
int main(){
    char filename [] = "squares.dat";
    FILE *fp = fopen(filename, "w");
    if (fp == NULL){
        perror("");
        return 1;
    }
    int n;
    printf("Input a integer:\n");
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        fprintf(fp,"%d\n",i*i);
    }
    fclose(fp);
}