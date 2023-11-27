#include<stdio.h>
void sumup(int a[][5],int *score){
    for(int i=0;i<4;++i) score[i]=0;
    for(int i=0;i<4;++i){
        for(int j=0;j<5;++j) score[i]+=a[i][j];
    }
}
float avg(int *score){
    float avg;
    for(int i=0;i<4;++i) avg+=score[i];
    avg/=4;
    return avg;
}
int main(){
    int a[4][5];
    int score[4];
    srand(time(NULL));
    for(int i=0;i<4;++i){
        for(int j=0;j<5;++j){
            a[i][j]=rand()%25;
            printf("%d ",a[i][j]);
            }
        printf("\n");
    }
    sumup(a,score);
    for(int i=0;i<4;++i) printf("%d ",score[i]);
    printf("%.2f",avg(score));
}