#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node_s{
    int data;
    struct node_s *next;
}node_t;
int main(){
    int i=0,j=0,input1=0,input2=0,c1=0,c2=0,s1=0,s2=0,f1=0;
    node_t *root[10];
    node_t *node=NULL;
    node_t *now=NULL;
    char root_name[10][20];
    char input_name[20];
    while(1){
        //printf("%d zz\n",c1);
        for(i=0;i<20;i++)
            input_name[i]='\0';
        scanf("%d",&input1);
        if(input1==1){
            scanf("%s",input_name);
            strcpy(root_name[c1],input_name);
            root[c1]=NULL;
            c1++;
        }
        else if(input1==2){
            scanf("%s",input_name);
            for(i=0;i<c1;i++){
                if(strcmp(root_name[i],input_name)==0){
                    node=(node_t*)malloc(sizeof(node_t));
                    scanf("%d",&input2);
                    node->data=input2;
                    node->next=NULL;
                    now=root[i];
                    if(root[i]==NULL)
                        root[i]=node;
                    else{
                        while(now->next!=NULL)
                            now=now->next;
                        now->next=node;
                    }
                    break;
                }
            }
            if(i==c1){
                //scanf("%d",&input2);
                printf("Queue %s isn't exist\n",input_name);
            }
        }
        else if(input1==3){
            scanf("%s",input_name);
            for(i=0;i<c1;i++){
                if(strcmp(root_name[i],input_name)==0){
                    now=root[i];
                    if(root[i]==NULL)
                        printf("Queue is empty\n");
                    else{
                        root[i]=now->next;
                        free(now);
                    }
                    break;
                }
            }
            if(i==c1)
                printf("Queue %s isn't exist\n",input_name);
        }
        else if(input1==4){
            f1=0;
            scanf("%s",input_name);
            for(i=0;i<c1;i++){
                if(strcmp(root_name[i],input_name)==0){
                    s1=i;
                    break;
                }
            }
            if(i==c1){
                f1=1;
                printf("Queue %s isn't exist\n",input_name);
            }
            for(i=0;i<20;i++)
                input_name[i]='\0';
            scanf("%s",input_name);
            for(i=0;i<c1;i++){
                if(strcmp(root_name[i],input_name)==0){
                    s2=i;
                    break;
                }
            }
            if(i==c1){
                f1=1;
                printf("Queue %s isn't exist\n",input_name);
            }
            if(f1==0){
                now=root[s1];
                if(now==NULL)
                    root[s1]=root[s2];
                else{
                    while(now->next!=NULL)
                        now=now->next;
                    now->next=root[s2];
                }
                for(i=0;i<20;i++)
                    root_name[s2][i]='\0';
                root[s2]=NULL;
            }
        }
        else if(input1==5){
            printf("****************************************\n");
            if(c1==0)
                printf("Isn't have any queue\n");
            else{
                for(i=0;i<c1;i++){
                    c2=1;
                    now=root[i];
                    if(root[i]==NULL)
                        c2=0;
                    else{
                        while(now->next!=NULL){
                            c2++;
                            now=now->next;
                        }
                    }
                    if(root_name[i][0]!='\0'){
                        printf("Queue Name:%s Queue Size:%d Queue Element:",root_name[i],c2);
                        now=root[i];
                        if(c2==0)
                            printf("Queue is empty\n");
                        else{
                            while(now->next!=NULL){
                                printf("%d ",now->data);
                                now=now->next;
                            }
                            printf("%d \n",now->data);
                        }
                    }
                }
            }
            printf("****************************************\n");
        }
        else if(input1==6)
            break;
    }
    return 0;
}
