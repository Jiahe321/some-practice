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
        printf("not prime");
        break;
        }
    }
    if(i==a/2+1) printf("is prime\n");
}
char  concatStrings(char a[], char b[]){
    char c[32767];
    int i=0,j=0;
    while(a[i]!='\0'){
        c[i]=a[i];
        ++i;
    }
    while(b[j]!='\0'){
        c[i]=b[j];
        ++i; ++j;
    }
    return c;
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
    concatStrings(a,b);

}