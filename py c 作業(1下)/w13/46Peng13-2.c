#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct University_s{
char name[20];
int BC;
int NC;
int CT;
int NS;
int NM;
int HL;
int NL;
struct University_s* next;
}University_t;
void clear_Uni(char Uni_all[10][20]){
    int i=0,j=0;
    for(i=0;i<10;i++){
        for(j=0;j<20;j++)
            Uni_all[i][j]='\0';
    }
}
int mystrtok(char s1[50],char *word[10],char split){
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
int choose_University(University_t *root,char attribute[],char Uni_all[10][20]){
    int i=0,j=0,count=0,att_num=0;
    University_t *now=root;
    for(i=0;i<strlen(attribute);i++){
        if((attribute[i]>='A')&&(attribute[i]<='Z'))
            att_num++;
    }
    att_num=att_num/2;
    while(now!=NULL){
        count=0;
        if(strstr(attribute,"BC")!=0){
            if(now->BC==1)
                count++;
        }
        if(strstr(attribute,"NC")!=0){
            if(now->NC==1)
                count++;
        }
        if(strstr(attribute,"CT")!=0){
            if(now->CT==1)
                count++;
        }
        if(strstr(attribute,"NS")!=0){
            if(now->NS==1)
                count++;
        }
        if(strstr(attribute,"NM")!=0){
            if(now->NM==1)
                count++;
        }
        if(strstr(attribute,"HL")!=0){
            if(now->HL==1)
                count++;
        }
        if(strstr(attribute,"NL")!=0){
            if(now->NL==1)
                count++;
        }
        if(count==att_num){
            for(i=0;i<10;i++){
                if(strcmp(Uni_all[i],now->name)==0)
                    break;
            }
            for(j=0;j<10;j++){
                if((Uni_all[j][0]=='\0')&&(i==10)){
                    strcpy(Uni_all[j],now->name);
                    break;
                }
            }
        }
        now=now->next;
    }
    for(j=0;j<10;j++){
        if(Uni_all[j][0]=='\0')
            break;
    }
    return j;
}
void print_sort1(char University_ch[10][20],int c1){
    int i=0,j=0,c2=0;
    char result[10][20];
    for(i=0;i<c1;i++){
        c2=0;
        for(j=0;j<c1;j++){
            if(strcmp(University_ch[i],University_ch[j])>0)
                c2++;
        }
        strcpy(result[c2],University_ch[i]);
    }
    for(i=0;i<c1;i++)
        printf("%s ",result[i]);
    printf("\n");
}
void decide_character(University_t *node1,char *word[10],int n){
    int i=0;
    node1->BC=0;
    node1->NC=0;
    node1->CT=0;
    node1->NS=0;
    node1->NM=0;
    node1->HL=0;
    node1->NL=0;
    for(i=1;i<n;i++){
        if(strcmp(word[i],"BC")==0)
            node1->BC=1;
        else if(strcmp(word[i],"NC")==0)
            node1->NC=1;
        else if(strcmp(word[i],"CT")==0)
            node1->CT=1;
        else if(strcmp(word[i],"NS")==0)
            node1->NS=1;
        else if(strcmp(word[i],"NM")==0)
            node1->NM=1;
        else if(strcmp(word[i],"HL")==0)
            node1->HL=1;
        else if(strcmp(word[i],"NL")==0)
            node1->NL=1;
    }
}
int main(){
    int i=0,j=0,c1=0,n=0,c2=0;
    University_t *root=NULL;
    University_t *now=NULL;
    University_t *node=NULL;
    char input_d[50];
    char *word[10];
    char Uni_all[10][20];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<50;j++)
            input_d[i]='\0';
        for(j=0;j<10;j++)
            word[i]=NULL;
        scanf(" %[^\n]",input_d);
        c1=mystrtok(input_d,word,' ');
        node=(University_t*)malloc(sizeof(University_t));
        node->next=NULL;
        strcpy(node->name,word[0]);
        decide_character(node,word,c1);
        if(root==NULL)
            root=node;
        else{
            now=root;
            while(now->next!=NULL)
                now=now->next;
            now->next=node;
        }
    }
    scanf("%d",&n);
    for(i=0;i<n;i++){
        clear_Uni(Uni_all);
        for(j=0;j<50;j++)
            input_d[i]='\0';
        for(j=0;j<10;j++)
            word[i]=NULL;
        scanf(" %[^\n]",input_d);
        c1=mystrtok(input_d,word,'+');
        for(j=0;j<c1;j++)
            c2=choose_University(root,word[j],Uni_all);
        print_sort1(Uni_all,c2);
    }
    return 0;
}
