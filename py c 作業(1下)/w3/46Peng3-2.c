#include <stdio.h>
#include <string.h>
void string_remove(char *s1,char *s2,char *list_in){
    int i=0,j=0,c1=0;
    char list_result[100]={'\0'};
    for(i=0;i<strlen(s1);i++){
        if(*(s1+i)==*s2){
            for(j=0;j<strlen(s2);j++){
                if(*(s1+i+j)!=*(s2+j))
                    break;
            }
            if(j==strlen(s2))
                i+=strlen(s2);
        }
        if(i<strlen(s1)){
            list_result[c1]=*(s1+i);
            c1+=1;
        }
    }
    for(i=0;i<strlen(list_result)+1;i++){
        *(list_in+i)=list_result[i];
    }
}
int compare_string(char *s1,char *s2,int rank){
    int i=0,j=0;
    while((*s1!='\0')&&(*s2!='\0')){
        if(*s1>*s2)
            return rank;
        else if(*s1<*s2)
            return rank-1;
        s1++;
        s2++;
    }
    if((*s1=='\0')&&(*s2!='\0'))
        return rank-1;
    else if((*s2=='\0')&&(*s1!='\0'))
        return rank;
    else
        return rank-1;
}

int main(){
    int i=0,j=0,c1=0,c2=0,c3=1;
    char list_in[100][100]={'a'},list_result[100][100]={'\0'};
    char list_remove[100],list_data[100];
    while(1){
        if(c1==0){
            scanf("%s",list_remove);
            if(list_remove[0]=='-')
                break;
        }
        scanf("%s",list_data);
        if(list_data[0]=='-')
            break;
        string_remove(list_data,list_remove,list_in[c1]);
        c1+=1;
    }
    for(i=0;i<c1;i++){
        c2=c1;
        for(j=0;j<c1;j++){
            if(i!=j){
                c2=compare_string(list_in[i],list_in[j],c2);
            }
        }
        strcpy(list_result[c2-1],list_in[i]);
    }
    for(i=0;i<c1;i++){
        printf("%s\n",list_result[i]);
    }
    return 0;
}

