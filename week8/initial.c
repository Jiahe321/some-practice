#include <stdio.h>
void transpose(int a[2][3]){
    puts("before:\n");
    for(int i=0;i<2;++i){
        for(int j=0;j<3;++j){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    puts("after:\n");
    for(int i=0;i<3;++i){
        for(int j=0;j<2;++j){
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}
void score_initial(int score[4][5]){
    srand(time(NULL));
    int sum =0;
    for(int i=0;i<4;++i){
        for(int j=0;j<5;++j){
            score[i][j]= rand()%25;
            printf("%d\t",score[i][j]);
            sum += score[i][j];
        }
        printf("\n");
    }
}
float average(int score[4][5], int subject){
    float avg =0;
    for(int i=0;i<5;++i){
            avg+=score[subject][i];
        }
        printf("average score of subject %d is:%f\n",subject,avg/5);
}
void score_initial2(int ss[2][3][4]){
    srand(time(NULL));
    int sum =0;
    for(int i=0;i<2;++i){
        for(int j=0;j<3;++j){
            for(int k=0;k<4;++k){
                ss[i][j][k]= rand()%31+70;
            }
        }
        printf("\n");
    }
}
void smm(int ss[2][3][4], int semester){
    for(int j=0;j<3;++j){
        for(int k=0;k<4;++k){
            printf("%d ",ss[semester][j][k]);
        }
        printf("\n");
    }
    printf("\n");
}
int main(){
    int a[2][3]={{0,1,2},{3,4,5}};
    transpose(a);

    int score[4][5];
    score_initial(score);
    average(score, 3);

    int ss[2][3][4];
    score_initial2(ss);
    smm(ss,0);
}