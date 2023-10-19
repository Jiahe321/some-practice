#include<stdio.h>
#include<string.h>
#include<math.h>
#define PI 3.1415926
int main(){
    //e1
    /*printf("Hello, World!");
    return 0;*/
    //e2
    /*int a,b;
    puts("Imput 2 integers:");
    scanf("%d%d",&a,&b);
    printf("the sum is: %d\n",a+b);
    return 0;*/
    //e3
    /*printf("the max data sizes:\n");
    printf("int %d\n",sizeof(int));
    printf("float %d\n",sizeof(float));
    printf("double %d\n",sizeof(double));
    printf("char %d\n",sizeof(char));*/
    //e4
    /*float r;
    puts("input the radius of a circle:");
    scanf("%f",&r);
    printf("the area of the circle is: %f\n", PI*r*r);*/
    //e5
    /*int a,b,c;
    puts("Imput 2 integers:\n");
    scanf("%d%d",&a,&b);
    c=a;a=b;b=c;*/
    //e6
    /*int a;
    while(scanf("%d",&a)!=EOF){
        if(a%2==0) printf("even\n");
        else printf("odd\n");
    }*/
    //e7
    /*float f, c;
    printf("input F°:\n");
    scanf("%f", &f);
    c=(f-32)*5.0/9.0;
    printf("C° is: %.2f\n", c);*/
    //e8
    /*int a,i,factorial;
    while(scanf("%d",&a)!=EOF){
        factorial=1;
        puts("Imput a integers\n");
        for(i=1;i<=a;++i){
            factorial*=i;
        }
        printf("the factorial is: %d\n",factorial);
    }*/
    //e9
    /*long long int v=3e8, day;
    puts("Input the days for lights travelling:\n");
    scanf("%lld",&day);
    printf("The distance is: %lld\n",v*day);*/
    //e10
    float principal, rate, time, simple_interest;
    printf("Enter the principal, interest rate (in percentage), and time period (in years）: ");
    scanf("%f%f%f", &principal,&rate,&time);
    printf("Simple Interest: %.2f\n", (principal * rate * time) / 100);
}