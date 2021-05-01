#include <stdio.h>
#include <string.h>
int compare(char list1[100],char list2[100]){
    int i=0;
    char list1_1[100]={'\0'};
    for(i=0;i<strlen(list1);i++){
        if((list1[i]>='A')&&(list1[i]<='Z'))
            list1_1[i]=list1[i]+32;
        else if((list1[i]>='a')&&(list1[i]<='z'))
            list1_1[i]=list1[i];
    }
    return strcmp(list1_1,list2);
}
void put_voca(char list_result[5][100][100],int st,int end,char* list_re,int c1){
    int i=0,j=0,c2=0;
    for(i=st;i<=end;i++){
        for(j=0;j<strlen(list_result[c1][i]);j++){
            *(list_re+j+c2)=list_result[c1][i][j];
        }
        if(i!=end)
            *(list_re+j+c2)=' ';
        else if(i==end)
            *(list_re+j+c2)='\0';
        c2+=j+1;
    }
}
void sort1(char list1[100][100],char arr_order,char list_P_big[100],int c1){
    int i=0,j=0,k=0,c2=0,c3=0,c4=0;
    int list_pass[100]={0};
    char list_data[100][100]={'a'},list_reverse[100]={'\0'};
    if(arr_order=='L'){
        for(i=0;i<c1;i++){
            c3=0;
            for(j=0;j<strlen(list1[i]);j++){
                c2=0;
                if(list1[i][j]==list_P_big[0]){
                    for(k=0;k<strlen(list_P_big);k++){
                        if(list1[i][j+k]==list_P_big[k])
                            c2+=1;
                    }
                }
                if(c2==strlen(list_P_big)){
                    list_data[i][c3]='\0';
                    break;
                }
                if(list1[i][j]!=' '){
                    list_data[i][c3]=list1[i][j];
                    c3++;
                }
            }
        }
        for(i=0;i<c1;i++){
            for(j=strlen(list_data[i])-1;j>=0;j--)
                list_reverse[strlen(list_data[i])-j-1]=list_data[i][j];
            strcpy(list_data[i],list_reverse);
            for(j=0;j<100;j++)
                list_reverse[j]='\0';
        }
    }
    else if(arr_order=='R'){
        for(i=0;i<c1;i++){
            c3=0;
            c4=0;
            for(j=0;j<strlen(list1[i]);j++){
                c2=0;
                if(list1[i][j]==list_P_big[0]){
                    for(k=0;k<strlen(list_P_big);k++){
                        if(list1[i][j+k]==list_P_big[k])
                            c2+=1;
                    }
                }
                if(c2==strlen(list_P_big)){
                    j+=strlen(list_P_big);
                    c4=1;
                }
                if((list1[i][j]!=' ')&&(c4==1)){
                    list_data[i][c3]=list1[i][j];
                    c3++;
                }
            }
            list_data[i][c3]='\0';
        }
    }
    for(i=0;i<c1;i++){
        for(j=0;j<c1;j++){
            if(list_pass[j]==0){
                c3=j;
                break;
            }
        }
        for(j=0;j<c1;j++){
            if(c3==j)
                continue;
            if((strlen(list_data[c3])>strlen(list_data[j]))&&(list_pass[j]==0))
                c3=j;
            else if(strlen(list_data[c3])==strlen(list_data[j])){
                for(k=0;k<strlen(list_data[c3]);k++){
                    if((list_data[c3][k]>list_data[j][k])&&(list_pass[j]==0)){
                        c3=j;
                        break;
                    }
                    else if(list_data[c3][k]<list_data[j][k])
                        break;
                }
            }
        }
        for(j=0;j<strlen(list1[c3]);j++){
            if((list1[c3][j]>='A')&&(list1[c3][j]<='Z')){
                c2=0;
                if(list1[c3][j]==list_P_big[0]){
                    for(k=0;k<strlen(list_P_big);k++){
                        if(list1[c3][j+k]==list_P_big[k])
                            c2+=1;
                    }
                }
                if(c2==strlen(list_P_big)){
                    for(k=0;k<strlen(list_P_big);k++){
                        printf("%c",list_P_big[k]);
                    }
                    j+=strlen(list_P_big)-1;
                }
                else
                    printf("%c",list1[c3][j]+32);
            }
            else if(list1[c3][j]!='\0'){
                printf("%c",list1[c3][j]);
            }
        }
        printf("\n");
        list_pass[c3]=1;
    }
}
void funcccc(char list_result[5][100][100],char list_P[100],char list_P_big[100],char arr_order,int num,int c3,int count_voca[5]){
    int i=0,j=0,k=0,s1=1,c1=0;
    int d_start=0,d_end=0;
    char list_re[100][100]={'\0'},list_copy[100];
    for(i=0;i<c3;i++){
        for(j=0;j<count_voca[i];j++){
            if(strlen(list_result[i][j])==strlen(list_P))
                s1=compare(list_result[i][j],list_P);
            if(s1==0){
                strcpy(list_copy,list_result[i][j]);
                strcpy(list_result[i][j],list_P_big);
                if(j-num<0)
                    d_start=0;
                else
                    d_start=j-num;
                if(j+num>count_voca[i])
                    d_end=count_voca[i]-1;
                else
                    d_end=j+num;
                put_voca(list_result,d_start,d_end,list_re[c1],i);
                s1=1;
                c1+=1;
                strcpy(list_result[i][j],list_copy);
            }
        }
    }
    sort1(list_re,arr_order,list_P_big,c1);
}

int main(){
    int n=0,i=0,j=0,k=0,c1=0,c2=0,c3=0,f1=1;
    int count_voca[5]={0};
    char list_in[300],list_result[5][100][100]={' '};
    char list_P[100],list_P_big[100],arr_order;
    scanf("%s %d %c\n",list_P,&n,&arr_order);
    for(i=0;i<5;i++){
        scanf(" %[^\n]",list_in);
        if(list_in[0]!='0'){
            f1=1;
            c1=0;
            c2=0;
            for(j=0;j<strlen(list_in);j++){
                if(list_in[j]=='\0')
                    break;
                if((list_in[j]!=' ')&&(list_in[j]!='\0')){
                    list_result[c3][c1][j-c2]=list_in[j];
                    f1=0;
                }
                else{
                    if(f1==0){
                        list_result[c3][c1][j-c2]='\0';
                        c1+=1;
                    }
                    c2=j+1;
                    f1=1;
                }
            }
            count_voca[c3]=c1;  //if necessary ,c1+1
            c3+=1;
        }
    }
    for(i=0;i<strlen(list_P);i++){
        if((list_P[i]>='A')&&(list_P[i]<='Z'))
            list_P[i]=list_P[i]+32;
    }
    for(i=0;i<strlen(list_P);i++)
            list_P_big[i]=list_P[i]-32;
    funcccc(list_result,list_P,list_P_big,arr_order,n,c3,count_voca);
    return 0;
}

