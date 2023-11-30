#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
bool closeStrings(char* word1, char* word2) {
    if(strlen(word1)!=strlen(word2)) return false;
    int count1[26]={0},count2[26]={0};
    for(int i = 0;word1[i] != '\0';i++){
        count1[word1[i]-'a']++;
        count2[word2[i]-'a']++;
    }
    for (int i=0;i<26;i++){
        if(count1[i]*count2[i]==0&&(count1[i]>0||count2[i] > 0)){
                return false;
        }
    }
    qsort(count1,26,sizeof(int),cmp);
    qsort(count2,26,sizeof(int),cmp);
    for(int i=0;i<26;++i){
        if(count1[i]!=count2[i]) return false;
    }
    return true;
}
int main(){
    char word1[10000],word2[10000];
    while(1){
        puts("plz input 2 words:");
        scanf("%s %s",word1,word2);
        printf("%d\n",closeStrings(word1,word2));
    }
}