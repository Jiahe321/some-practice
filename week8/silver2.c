#include<stdio.h>
void initial(int a[2][3][4]){
    for(int i=0;i<2;++i){
        printf("seme %d:\n",i+1);
        for(int j=0;j<3;++j){
            printf("stu %d:",j+1);
            for(int k=0;k<4;++k){
                a[i][j][k]=rand()%31+70;
                printf("%d ",a[i][j][k]);
                }
            printf("\n");
        }
        printf("\n");
    }
}
int main(){
    srand(time(NULL));
    int a[2][3][4];
    initial(a);
}