#include<stdio.h>
int main(){
    int a[5],sum=0;
    puts("input array:");
    for(int i=0;i<5;++i){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    //e1
    printf("the sum is %d\n",sum);
    //e2
    int t;
    for(int i=0;i<2;++i){
        t=a[i];
        a[i]=a[4-i];
        a[4-i]=t;
    }
    for(int i=0;i<5;++i) printf("%d ",a[i]);
    puts("\n");
    //e3
    int max=-32767;
    for(int i=0;i<5;++i){
        if(a[i]>max) max=a[i];
    }
    printf("max=%d\n",max);
    //e4
    int c=a[0];
    for(int i=1;i<5;++i){
        t=c;
        c=a[i];
        a[i]=t;
    }
    a[0]=c;
    for(int i=0;i<5;++i) printf("%d ",a[i]);
    puts("\n");
    //e5
    int count=0;
    int x[6][2],b[3];
    for(int i=0;i<6;++i){
        x[i][0]=rand();
        x[i][1]=0;
    }
    for(int i=0;i<6;++i){
        if(!x[i][1]){
            for(int j=i+1;j<6;++j){
                if(x[i][0]==x[j][0]){
                    x[i][1]=1;
                    x[j][1]=1;
                    b[count]=x[i][0];
                    count++;
                    for(int k=j+1;k<6;++k){
                        if(x[i][0]==x[k][0]){
                        x[k][1]=1;
                        }
                    }
                }
            }
        }
    }
    if(count){
        for(int i=0;i<count;++i) printf("%d ",b[i]);
    }
    else printf("No duplicate elements found!");
    //e6
    int aa1[3],aa2[3],co[6],f=1;
    for(int i=0;i<3;++i){
        aa1[i]=rand();
        aa2[i]=rand();
    }
    for(int i=0;i<6;++i){
        if(f) co[i]=aa1[i];
        else co[i]=aa2[i-3];
        if(i==2) f=0;
    }
}