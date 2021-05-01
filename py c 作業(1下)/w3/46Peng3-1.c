#include <stdio.h>
#include <string.h>
void count_string(char list1[100][100],int count1){
    int i=0,j=0,c1=0,c2=0,c3=0,list_cal[100]={0};
    char list_clear[100],list_result[100][100],list2[100][100];
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            list2[i][j]=list1[i][j];
        }
    }
    for(i=0;i<100;i++){
        list_clear[i]='0';
    }
    list_clear[99]='\0';
    for(i=0;i<count1;i++){
        if(strcmp(list2[i],list_clear)!=0){
            c1=0;
            strcpy(list_result[c3],list1[i]);
            for(j=0;j<count1;j++){
                if(strcmp(list1[i],list2[j])==0){
                    c1+=1;
                    strcpy(list2[j],list_clear);
                }
            }
            list_cal[c3]=c1;
            c3+=1;
        }
    }
    for(i=0;i<c3;i++){
        if(list_result[i][0]!='\0')
            printf("%s %d\n",list_result[i],list_cal[i]);
    }
}

int main(){
    int i=0,j=0,c1=0,c2=0,f1=0;
    char list_in[100],list_result[100][100]={'a'};
    gets(list_in);
    for(i=0;i<strlen(list_in);i++){
        if(((int)list_in[i]>=65)&&((int)list_in[i]<=90)){
            list_in[i]=(char)((int)list_in[i]+32);
        }
    }
    for(i=0;i<strlen(list_in);i++){
        if((list_in[i]!=' ')&&(list_in[i]!='\0')){
            list_result[c1][i-c2]=list_in[i];
            f1=0;
        }
        else{
            if(f1==0){
                list_result[c1][i-c2+1]='\0';
                c1+=1;
            }
            c2=i+1;
            f1=1;
        }
    }
    count_string(list_result,c1+1);
    return 0;
}

