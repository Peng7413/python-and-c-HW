#include <stdio.h>
#include <string.h>
int pow1(int num){
    int i=0,c1=1;
    for(i=0;i<num;i++)
        c1*=10;
    return c1;
}
void decode1(char clue[100][100],int count1){
    int i=0,j=0,c1=0,c2=0;
    for(i=count1;i>=0;i--){
        if(((int)clue[i][0]>=48)&&((int)clue[i][0]<58)){
            for(j=strlen(clue[i])-1;j>=0;j--){
                c2=pow1(j);
                c1+=((int)clue[i][j]-48)*c2;
            }
        }
    }
    c1=c1%10000;
    for(i=3;i>=0;i--){
        c2=pow1(i);
        printf("%d",c1/c2);
        c1=c1%c2;
    }

}
void decode2(char clue[300],int *count){
    int i=0,j=0;
    for(i=0;i<26;i++){
        for(j=0;j<strlen(clue);j++){
            if(clue[j]==((char)(65+i)))
                *(count+i)+=1;
        }
    }
    for(i=26;i<52;i++){
        for(j=0;j<strlen(clue);j++){
            if(clue[j]==((char)(97+i-26)))
                *(count+i)+=1;
        }
    }
    for(i=0;i<strlen(clue);i++){
        if((((int)clue[i])>=65)&&(((int)clue[i])<91)){
            if((*(count+((int)clue[i]-65))<10)&&(*(count+((int)clue[i]-65))>0))
                printf("%d",*(count+((int)clue[i]-65)));
                *(count+((int)clue[i]-65))=0;
        }
        else if((((int)clue[i])>=97)&&(((int)clue[i])<123)){
            if((*(count+((int)clue[i]-97)+26)<10)&&(*(count+((int)clue[i]-97)+26)>0))
                printf("%d",*(count+((int)clue[+i]-97)+26));
                *(count+((int)clue[+i]-97)+26)=0;
        }
        else if((((int)clue[i])>=48)&&(((int)clue[i])<58))
            printf("%c",clue[i]);
    }
}
int main(){
    int i=0,j=0,c1=0,c2=0,f1=0;
    int list_count[52]={0};
    char list_clue1[300],list_clue2[300];
    char list_clue1_1[100][100]={'a'};
    gets(list_clue1);
    gets(list_clue2);
    for(i=0;i<strlen(list_clue1);i++){
        if(((int)list_clue1[i]>=48)&&((int)list_clue1[i]<58)){
            list_clue1_1[c1][i-c2]=list_clue1[i];
            f1=0;
        }
        else{
            if(f1==0){
                list_clue1_1[c1][i-c2+1]='\0';
                c1+=1;
            }
            c2=i+1;
            f1=1;
        }
    }
    decode1(list_clue1_1,c1);
    decode2(list_clue2,list_count);
    return 0;
}

