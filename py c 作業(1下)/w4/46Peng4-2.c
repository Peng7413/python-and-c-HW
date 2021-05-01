#include <stdio.h>
#include <string.h>
void replace(char list_sentence[100][100],char list_P[],char list_Q[],int count1){
    int i=0,j=0;
    for(i=0;i<count1;i++){
        if(strcmp(list_sentence[i],list_P)==0){
            printf("%s ",list_Q);
        }
        else
            printf("%s ",list_sentence[i]);
    }
    printf("\n");
    for(i=0;i<count1;i++){
        if(strcmp(list_sentence[i],list_P)==0){
            printf("%s ",list_Q);
        }
        printf("%s ",list_sentence[i]);
    }
    printf("\n");
    for(i=0;i<count1;i++){
        if(strcmp(list_sentence[i],list_P)==0){
            i+=1;
        }
        printf("%s ",list_sentence[i]);
    }
    printf("\n");
}
int compare_string(char *s1,char *s2){
    int i=0,j=0;
    while((*s1!='\0')&&(*s2!='\0')){
        if(*s1>*s2)
            return 0;
        else if(*s1<*s2)
            return 1;
        s1++;
        s2++;
    }
    if((*s1=='\0')&&(*s2!='\0'))
        return 1;
    else if((*s2=='\0')&&(*s1!='\0'))
        return 0;
    else
        return 0;
}
void arrange(char list1[100][100],int list_cal[100],int count1){
    int i=0,j=0,max_index=0,max=0,c1=0;
    for(i=0;i<count1;i++){
        max_index=0;
        max=list_cal[0];
        for(j=0;j<count1;j++){
            if(max<list_cal[j]){
                max=list_cal[j];
                max_index=j;
            }
            else if((max==list_cal[j])&&(i!=j)){
                c1=compare_string(list1[max_index],list1[j]);
                if(c1!=1)
                    max_index=j;
                    max=list_cal[j];
            }
        }
        printf("%s %d\n",list1[max_index],list_cal[max_index]);
        list_cal[max_index]=0;
    }
}
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
    arrange(list_result,list_cal,c3);
}

int main(){
    int i=0,j=0,c1=0,c2=0,f1=1;
    char list_in[100],list_result[100][100]={'a'};
    char list_P[100],list_Q[100];
    gets(list_in);
    scanf("%s",list_P);
    scanf("%s",list_Q);
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
    replace(list_result,list_P,list_Q,c1+1);
    count_string(list_result,c1+1);
    return 0;
}

