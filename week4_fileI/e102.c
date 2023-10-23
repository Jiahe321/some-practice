#include<stdio.h>
#include<stdlib.h>// exit(), atof().
int main(){
    char filename [] = "numbers.dat";
    FILE *fp = fopen(filename, "a+");
    if (fp == NULL){
        perror("");
        exit(1);// Exits program with return status 1.
    }
    float sum=0,x;
    int count=0;
    char ch[999];
    // 将文件指针移动到文件的开头
    fseek(fp, 0, SEEK_SET);
    while(fgets(ch,sizeof(ch),fp)!=NULL){
        x = atof(ch);
        sum+=x;
        count++;
    }
    // 将文件指针移动到文件末尾
    fseek(fp, 0, SEEK_END);
    fprintf(fp,"%f\n",sum/count);
    fclose(fp);
}