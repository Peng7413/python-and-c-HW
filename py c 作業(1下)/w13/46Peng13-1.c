#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Company_s{
char name[20];
char site[20];
char topic[20];
char country[20];
int award;
struct Company_s* next;
}Company_t;
int mystrtok(char s1[50],char *word[10]){
    int i=0,j=0,c1=0;
    char *posit;
    posit=&s1[0];
    while(s1[i]!='\0'){
        if(s1[i]==' '){
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
int trans_str_to_num(char s1[]){
    int i=0,base=1,num=0;
    for(i=strlen(s1)-1;i>=0;i--){
        if(i!=strlen(s1)-1)
            base=base*10;
        num+=(s1[i]-'0')*base;
    }
    return num;
}
void print_sort1(Company_t *root,char search[],int up_or_d){
    int i=0,j=0,c1=0,c2=0;
    Company_t *now=root,*now2=NULL;
    while(now!=NULL){
        now=now->next;
        c1++;
    }
    char data[c1][20],data_site[c1][20];
    char name_all[c1][20],site_all[c1][20];
    int data_award[c1];
    now=root;
    while(now!=NULL){
        strcpy(data_site[c2],now->site);
        if(strcmp(search,"name")==0)
            strcpy(data[c2],now->name);
        else if(strcmp(search,"site")==0)
            strcpy(data[c2],now->site);
        else if(strcmp(search,"topic")==0)
            strcpy(data[c2],now->topic);
        else if(strcmp(search,"country")==0)
            strcpy(data[c2],now->country);
        else if(strcmp(search,"award")==0)
            data_award[c2]=now->award;
        c2++;
        now=now->next;
    }
    now=root;
    if(strcmp(search,"award")==0){
        for(i=0;i<c1;i++){
            c2=0;
            for(j=0;j<c1;j++){
                if(up_or_d==1){
                    if(data_award[i]<data_award[j])
                        c2++;
                    else if(data_award[i]==data_award[j]){
                        if(strcmp(data_site[i],data_site[j])<0)
                            c2++;
                    }
                }
                else if(up_or_d==2){
                    if(data_award[i]>data_award[j])
                        c2++;
                    else if(data_award[i]==data_award[j]){
                        if(strcmp(data_site[i],data_site[j])>0)
                            c2++;
                    }
                }
            }
            strcpy(name_all[c2],now->name);
            strcpy(site_all[c2],now->site);
            now=now->next;
        }
    }
    else{
        for(i=0;i<c1;i++){
            c2=0;
            for(j=0;j<c1;j++){
                if(up_or_d==1){
                    if(strcmp(data[i],data[j])<0)
                        c2++;
                    else if(strcmp(data[i],data[j])==0){
                        if(strcmp(data_site[i],data_site[j])<0)
                            c2++;
                    }
                }
                else if(up_or_d==2){
                    if(strcmp(data[i],data[j])>0)
                        c2++;
                    else if(strcmp(data[i],data[j])==0){
                        if(strcmp(data_site[i],data_site[j])>0)
                            c2++;
                    }
                }
            }
            strcpy(name_all[c2],now->name);
            strcpy(site_all[c2],now->site);
            now=now->next;
        }
    }
    for(i=0;i<c1;i++)
        printf("%s %s\n",name_all[i],site_all[i]);
    printf("\n");
}
int main(){
    int i=0,j=0,c1=0;
    Company_t *root=NULL;
    Company_t *now=NULL;
    Company_t *node=NULL;
    char input_d[50];
    char *word[10];
    while(1){
        for(i=0;i<50;i++)
            input_d[i]='\0';
        for(i=0;i<10;i++)
            word[i]=NULL;
        gets(input_d);
        if(strcmp(input_d,"-1")==0)
            break;
        c1=mystrtok(input_d,word);
        node=(Company_t*)malloc(sizeof(Company_t));
        strcpy(node->name,word[0]);
        strcpy(node->site,word[1]);
        strcpy(node->topic,word[2]);
        strcpy(node->country,word[3]);
        node->award=trans_str_to_num(word[4]);
        node->next=NULL;
        if(root==NULL)
            root=node;
        else{
            now=root;
            while(now->next!=NULL)
                now=now->next;
            now->next=node;
        }
    }
    while(1){
        for(i=0;i<50;i++)
            input_d[i]='\0';
        for(i=0;i<10;i++)
            word[i]=NULL;
        gets(input_d);
        if(strcmp(input_d,"exit")==0)
            break;
        c1=mystrtok(input_d,word);
        print_sort1(root,word[0],word[1][0]-'0');
    }
    return 0;
}
