#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mystrtok(char s1[50],char *word[2],char split){
    int i=0,j=0,c1=0;
    char *posit;
    posit=&s1[0];
    while(s1[i]!='\0'){
        if(s1[i]==split){
            word[c1]=posit;
            s1[i]='\0';
            posit=&s1[i+1];
            c1++;
        }
        i++;
    }
    word[c1]=posit;
    c1++;
    return c1;
}
void preorder_and_inorder(char s1[20],char s2[20],int stack,char re[10][10]){
    int g,i;
    char *word[2];
    for(i=0;i<10;i++){
        if(re[stack][i]=='\0'){
            re[stack][i]=s2[0];
            break;
        }
    }
    g=mystrtok(s1,word,s2[0]);
    for(i=0;i<strlen(s2);i++)
        s2[i]=s2[i+1];
    if(strlen(word[0])!=0){
        preorder_and_inorder(word[0],s2,stack+1,re);
    }
    if(strlen(word[1])!=0){
        preorder_and_inorder(word[1],s2,stack+1,re);
    }
}
void postorder_and_inorder(char s1[20],char s2[20],int stack,char re[10][10]){
    int g,i,c1;
    char *word[2];
    c1=strlen(s2)-1;
    for(i=0;i<10;i++){
        if(re[stack][i]=='\0'){
            re[stack][i]=s2[c1];
            break;
        }
    }
    g=mystrtok(s1,word,s2[c1]);
    s2[c1]='\0';
    if(strlen(word[1])!=0){
        postorder_and_inorder(word[1],s2,stack+1,re);
    }
    if(strlen(word[0])!=0){
        postorder_and_inorder(word[0],s2,stack+1,re);
    }
}
int main(){
    int n=0,i=0,j=0,c1=0;
    char s1[20];
    char s2[20];
    char order1,order2;
    char *word[2];
    char re[10][10];
    for(i=0;i<10;i++){
        for(j=0;j<10;j++)
            re[i][j]='\0';
    }
    for(i=0;i<20;i++){
        s1[i]='\0';
        s2[i]='\0';
    }
    scanf(" %c",&order1);
    if(order1=='P'){
        c1=1;
        scanf(" %[^\n]",s2);
    }
    else if(order1=='I')
        scanf(" %[^\n]",s1);
    else if(order1=='O'){
        c1=2;
        scanf(" %[^\n]",s2);
    }
    scanf(" %c",&order2);
    if(order2=='P'){
        c1=1;
        scanf(" %[^\n]",s2);
    }
    else if(order2=='I')
        scanf(" %[^\n]",s1);
    else if(order2=='O'){
        c1=2;
        scanf(" %[^\n]",s2);
    }
    if(c1==1){
        preorder_and_inorder(s1,s2,1,re);
        for(i=0;i<10;i++){
            if(re[i][0]=='\0')
                continue;
            for(j=0;j<strlen(re[i]);j++)
                printf("%c",re[i][j]);
        }
    }
    else if(c1==2){
        postorder_and_inorder(s1,s2,1,re);
        for(i=0;i<10;i++){
            if(re[i][0]=='\0')
                continue;
            for(j=strlen(re[i])-1;j>=0;j--)
                printf("%c",re[i][j]);
        }
    }
    return 0;
}
