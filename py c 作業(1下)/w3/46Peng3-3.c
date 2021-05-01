#include <stdio.h>
#include <string.h>
int string_find(char *s1,char *s2){
    int i=0,j=0,k=0,c1=0;
    char list_result[100]={'\0'};
    for(k=0;k<strlen(s1);k++){
        for(i=0;i<=k;i++){
            for(j=0;j<100;j++)
                list_result[j]='\0';
            for(j=0;j<strlen(s1)-k;j++){
                list_result[j]=*(s1+i+j);
            }
            if(strstr(s2,list_result)!=0){
                printf("%s\n",list_result);
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int i=0,j=0,c1=0;
    char listA[100],listB[100];
    scanf("%s",listA);
    scanf("%s",listB);
    if(strlen(listB)>=strlen(listA))
        c1=string_find(listA,listB);
    else
        c1=string_find(listB,listA);
    return 0;
}

