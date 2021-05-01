#include <stdio.h>
#include <string.h>
int locatt(char name1,char all_name[10],int n){
    int i=0;
    for(i=0;i<n;i++){
        if(all_name[i]==name1)
            break;
    }
    return i;
}
int findpeople(char name1,char all_name[10]){
    int i=0;
    for(i=0;i<strlen(all_name);i++){
        if(name1==all_name[i])
            return 1;
    }
    return 0;
}
void deal(char stu[10][10],char teach[10][10],char stu_name[10],char teach_name[10],int n){
    int i=0,j=0,k=0,c1=0,c2=0;
    char teach_choosen[10][10]={'\0'};
    char partner[10][3];
    char clear1[10]="000000000";
    for(i=0;i<10;i++){
        for(j=0;j<3;j++)
            partner[i][j]='\0';
    }
    for(i=0;i<n;i++)
        partner[i][0]=stu_name[i];
    while(k<n){
        for(i=0;i<n;i++){
            c2=0;
            for(j=0;j<n;j++){
                if(stu[j][k]==teach_name[i]){
                    teach_choosen[i][c2]=stu_name[j];
                    c2++;
                }
            }
        }//2 1 0 1;A B C D
        for(i=0;i<n;i++){
            if(strlen(teach_choosen[i])==1){
                for(j=0;j<n;j++){
                    if(stu[j][k]==teach_name[i]){
                        partner[j][1]=teach_name[i];
                        strcpy(stu[j],clear1);
                        teach_name[i]='1';
                    }
                }
            }
            else if(strlen(teach_choosen[i])>1){
                for(j=0;j<n;j++){
                    c1=locatt(teach[i][j],stu_name,n);
                    if((partner[c1][1]=='\0')&&(findpeople(teach[i][j],teach_choosen[i])==1)){
                        partner[c1][1]=teach_name[i];
                        strcpy(stu[c1],clear1);
                        teach_name[i]='1';
                        break;
                    }
                }
            }
        }
        k++;
        for(i=0;i<10;i++){
            for(j=0;j<10;j++)
                teach_choosen[i][j]='\0';
        }
    }
    for(i=0;i<n;i++){
        printf("%c",partner[i][0]);
        printf("->");
        printf("%c\n",partner[i][1]);
    }
}
void sort1(char *list1,char *list2,int n){
    char list_eng[26]={'5'};
    char list_re[10]={'\0'};
    int i=0,c1=0;
    for(i=0;i<26;i++)
        list_eng[i]='0';
    for(i=0;i<n;i++){
        c1=*(list2+i)-65;
        list_eng[c1]=*(list2+i);
    }
    c1=0;
    for(i=0;i<26;i++){
        if((list_eng[i]>='A')&&(list_eng[i]<='Z')){
            *(list1+c1)=list_eng[i];
            c1++;
        }
    }
    *(list1+c1)='\0';
}
int main(){
    int i=0,j=0,c1=0,n=0;
    char stu[10][10]={'\0'},teach[10][10]={'\0'};
    char stu_name[10]={'\0'},teach_name[10]={'\0'};
    char input[30];
    for(j=0;j<30;j++)
        input[j]='\0';
    scanf("%s",input);
    j=0;
    while(input[j]!='\0'){
        if((input[j]>='A')&&(input[j]<='Z')){
            stu[0][n]=input[j];
            n++;
        }
        j++;
    }
    j=0;
    for(i=1;i<n;i++){
        for(j=0;j<30;j++)
            input[j]='\0';
        scanf("%s",input);
        c1=0;
        j=0;
        while(c1<n){
            if((input[j]>='A')&&(input[j]<='Z')){
                stu[i][c1]=input[j];
                c1++;
            }
            j++;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<30;j++)
            input[j]='\0';
        scanf("%s",input);
        c1=0;
        j=0;
        while(c1<n){
            if((input[j]>='A')&&(input[j]<='Z')){
                teach[i][c1]=input[j];
                c1++;
            }
            j++;
        }
    }
    sort1(stu_name,teach[0],strlen(teach[0]));
    sort1(teach_name,stu[0],strlen(stu[0]));
    deal(stu,teach,stu_name,teach_name,n);
    return 0;
}
