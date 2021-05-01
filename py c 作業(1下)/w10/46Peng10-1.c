#include <stdio.h>
#include <string.h>
typedef struct file_s{
    char name[10][20];
    int list_data[10][50];
    int file_size[10];
    int file_num;
}file_t;
void reset1(char *list1){
    int i=0;
    for(i=0;i<9;i++)
        *(list1+i)='\0';
}
void print1(char *list1){
    int i=0;
    for(i=0;i<8;i++)
        printf("%d ",*(list1+i)-'0');
    printf("\n");
}
void decimal_to_binary(int n,char *binary){
    int i=7;
    char c1;
    char re[9]="00000000";
    while(n/2>=1){
        c1=(n%2)+48;
        re[i]=c1;
        n=n/2;
        i--;
    }
    re[i]=n+48;
    for(i=0;i<12;i++)
        *(binary+i)=re[i];
}
int output_order(int out[50],int c1){
    int i=0;
    for(i=0;i<50;i++){
        if(out[i]==0){
            out[i]=c1;
            return i;
        }
    }
}
int write_file(file_t *file1){
    int input1=0,i=0,f1=0;
    char name1[20];
    for(i=0;i<20;i++)
        name1[i]='\0';
    scanf("%s",name1);
    for(i=0;i<file1->file_num;i++){
        if(strcmp(name1,file1->name[i])==0)
            f1=1;
    }
    i=0;
    if(f1==0)
        strcpy(file1->name[file1->file_num],name1);
    while(1){
        scanf("%d",&input1);
        if(input1==-1)
            break;
        if(f1==0)
            file1->list_data[file1->file_num][i]=input1;
        i++;
    }
    if(f1==0){
        file1->file_size[file1->file_num]=i;
        file1->file_num++;
    }

    return f1;
}
int read_file(file_t *file1,int out[50],int outdata[50][50]){
    int input1=0,i=0,c1=0,c2=0;
    char name1[20];
    for(i=0;i<20;i++)
        name1[i]='\0';
    scanf("%s",name1);
    for(i=0;i<file1->file_num;i++){
        if(strcmp(name1,file1->name[i])==0){
            c1=i;
            break;
        }
    }
    if(i==file1->file_num)
        c1=-2;
    c2=output_order(out,c1+1);
    if(c1!=-2){
        for(i=0;i<50;i++)
            outdata[c2][i]=file1->list_data[c1][i];
    }
    return 0;
}
int edit_file(file_t *file1){
    int input1=0,i=0,c1=0,m=0,n=0;
    char name1[20];
    for(i=0;i<20;i++)
        name1[i]='\0';
    scanf("%s",name1);
    for(i=0;i<file1->file_num;i++){
        if(strcmp(name1,file1->name[i])==0){
            c1=i;
            break;
        }
    }
    if(i==file1->file_num){
        return 1;
    }
    scanf("%d",&m);
    scanf("%d",&n);
    file1->list_data[c1][m-1]=n;
    return 0;
}
int main(){
    file_t file_all;
    file_all.file_num=0;
    char result_bin[9]={'\0'};
    int i=0,j=0,input1=0,re1;
    int list_output[50]={0},output_data[50][50]={0};
    for(i=0;i<10;i++){
        for(j=0;j<50;j++)
            file_all.list_data[i][j]=-1;
    }
    for(i=0;i<10;i++){
        for(j=0;j<20;j++)
            file_all.name[i][j]='\0';
    }
    while(1){
        re1=0;
        scanf("%d",&input1);
        if(input1==1)
            re1=write_file(&file_all);
        else if(input1==2)
            read_file(&file_all,list_output,output_data);
        else if(input1==3)
            re1=edit_file(&file_all);
        else if(input1==4)
            break;
        if(re1==1)
            output_order(list_output,-1);
    }
    i=0; j=0;
    while(list_output[j]!=0){
        if(list_output[j]==-1)
            printf("Error\n");
        else{
            i=0;
            printf("%d bytes\n",file_all.file_size[list_output[j]-1]);
            while(output_data[j][i]!=-1){
                decimal_to_binary(output_data[j][i],result_bin);
                print1(result_bin);
                reset1(result_bin);
                i++;
            }
        }
        j++;
    }
    return 0;
}
