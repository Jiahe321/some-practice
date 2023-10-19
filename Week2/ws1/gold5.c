#include<stdio.h>
int main(){
    int x;
    printf("1 for sec a, 2 for b, 3 for c, 4 for d, 5 for e: ");
    scanf("%d",&x);
    switch(x){
        case 1: puts("a");break;
        case 2: puts("b");break;
        case 3: puts("c");break;
        case 4: puts("d");break;
        case 5: puts("e");break;
        default: puts("error! invalid choice!");
    }
}