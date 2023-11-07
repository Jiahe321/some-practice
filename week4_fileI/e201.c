#include<stdio.h>
struct point{
    double x;
    double y;
}co[10];
int main(){
    for(int i=0;i<10;++i){
        co[i].x=(double)(rand() % 100) / 100.0;;
        co[i].y=(double)(rand() % 100) / 100.0;;
        printf("(%.2f,%.2f)\n",co[i].x,co[i].y);
    }
}