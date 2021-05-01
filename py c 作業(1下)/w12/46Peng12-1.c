#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Homework{
char name[10];
int isDelay;
struct Homework *next;
}HW;
char* mystrtok(char s1[20]){
    int i=0,j=0;
    char *posit;
    posit=&s1[0];
    while(s1[i]!='\0'){
        if(s1[i]==' '){
            s1[i]='\0';
            posit=&s1[i+1];
        }
        i++;
    }
    return posit;
}
int main(){
    int i=0,j=0,s1=0,s2=0;
    HW *root=NULL;
    HW *node=NULL;
    HW *now=NULL;
    char input_name[20];
    char *word;
    while(1){
        for(i=0;i<20;i++)
            input_name[i]='\0';
        gets(input_name);
        if(strcmp(input_name,"-1")==0)
            break;
        node=(HW*)malloc(sizeof(HW));
        strcpy(node->name,input_name);
        node->isDelay=0;
        node->next=NULL;
        if(s1==0){
            root=node;
            s1=1;
        }
        else{
            root=node;
            node->next=now;
        }
        now=node;
    }
    while(1){
        for(i=0;i<20;i++)
            input_name[i]='\0';
        gets(input_name);
        if(strcmp(input_name,"3")==0)
            break;
        else if(strcmp(input_name,"2")==0){
            if(root==NULL){
                printf("Empty\n");
            }
            else if(root->isDelay==1)
                printf("%s's HW is delay\n",root->name);
            else if(root->isDelay==0)
                printf("%s's HW is not delay\n",root->name);
            if(root!=NULL){
                now=root->next;
                free(root);
                root=now;
                if(root==NULL)
                    s1=0;
            }
        }
        else if(input_name[0]=='1'){
            node=(HW*)malloc(sizeof(HW));
            word=mystrtok(input_name);
            strcpy(node->name,word);
            node->isDelay=1;
            node->next=NULL;
            root=node;
            node->next=now;
            now=node;
        }
    }
    now=root;
    while(root!=NULL){
        s2=1;
        if(root->isDelay==1)
            printf("%s's HW is delay\n",root->name);
        else if(root->isDelay==0)
            printf("%s's HW is not delay\n",root->name);
        if(root!=NULL){
            now=root->next;
            free(root);
            root=now;
            if(root==NULL)
                s1=0;
        }
    }
    if((root==NULL)&&(s2==0))
        printf("Empty\n");
    return 0;
}
