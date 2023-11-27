#include<stdio.h>
#include<stdlib.h>
int main(){
    int x,y,z;
    puts("input 3 int:");
    scanf("%d%d%d",&x,&y,&z);
    int ***p=(int***)malloc(sizeof(int**)*x);
    for(int i=0;i<x;++i){
        p[i]=(int**)malloc(y*sizeof(int*));
        for(int j=0;j<y;++j){
            p[i][j]=(int*)malloc(z*sizeof(int));
            for(int k=0;k<z;++k){
                p[i][j][k]=(i+1)*(j+1)*(k+1);
                printf("p[%d][%d][%d]=%d\n",i,j,k,p[i][j][k]);
            }
        }
    }
}