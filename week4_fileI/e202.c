#include<stdio.h>
#include<math.h>
struct point{
    double x;
    double y;
}co[100];
int main(){
    int n;
    double quantity;
    //initialize
    for(int i=0;i<100;++i){
        co[i].x= (double)rand() / 100;
        co[i].y= (double)rand() / 100;
    }
    puts("pls input a integer between 1 to 99:");
    scanf("%d",&n);
    for(int i=0;i<n-1;++i){
        quantity+=fabs(co[i].x-co[i+1].x)+fabs(co[i].y-co[i+1].y);
    }
    quantity/=n+1;
    printf("%.5f",quantity);
}