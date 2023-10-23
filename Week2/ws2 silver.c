#include<stdio.h>
int str_lan(char a[]){
    int count=0;
    while(a[count]!='\0'){
        ++count;
    }
    return count;
}
void isPrime(int a){
    int i;
    for(i=2;i<=a/2;++i){
        if(a%i==0){
        printf("not prime\n");
        break;
        }
    }
    if(i==a/2+1) printf("is prime\n");
}
void concatStrings(char a[], char b[],char *c){
    for(int i=0;i<str_lan(a)+str_lan(b);++i){
        if(i<str_lan(a)){
            c[i]=a[i];
        }
        else{
            c[i]=b[i-str_lan(a)];
        }
    }
}
float performOperation(float num1, float num2, char operator) {
    switch (operator) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0) {
                return num1 / num2;
            } else {
                printf("Error: Division by zero is not allowed.\n");
                return 0.0; // You can handle this error as needed
            }
        default:
            printf("Error: Invalid operator.\n");
            return 0.0; // You can handle this error as needed
    }
}
int main(){
    char a[9999],b[9999],c[32767];
    puts("Enter a string:\n");
    scanf("%s",a);
    printf("The lenth is %d\n",str_lan(a));

    int x;
    puts("Enter an integer:\n");
    scanf("%d",&x);
    isPrime(x);

    scanf("%s",a);
    scanf("%s",b);
    concatStrings(a,b,c);
    printf("%s\n",c);

    float num1, num2;
    char operator;

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator); // Notice the space before %c to consume any leading whitespace

    float result = performOperation(num1, num2, operator);
    printf("Result: %.2f\n", result);
}