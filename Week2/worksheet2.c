#include<stdio.h>
float circleArea(float r){
    return 3.1415926*r*r;
}
float volume(float r){
    return 3/4.0*3.1415926*r*r;
}
int main(){
    float r;
    puts("Enter the radius:\n");
    scanf("%f",&r);
    printf("The area is %f\n",circleArea(r));
    printf("The volume is %f\n",volume(r));
}