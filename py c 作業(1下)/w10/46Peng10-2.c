#include <stdio.h>
#include <string.h>
typedef struct file_s{
    char name[50][20];
    char data[50][50][50];
    int line1[50];
    int file_num;
}file_t;
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
void sort_file(file_t file1,int print_arr[],int num){
    int name1[50];
    int i=0,j=0,c1=0;
    for(i=0;i<num;i++){
        c1=0;
        for(j=0;j<num;j++){
            if(i!=j){
                if(strcmp(file1.name[print_arr[i]],file1.name[print_arr[j]])>0)
                    c1++;
            }
        }
        name1[c1]=i;
    }
    for(i=0;i<num;i++){
        for(j=0;j<file1.line1[name1[i]];j++)
            printf("%s\n",file1.data[name1[i]][j]);
    }
}
void sort_file2(file_t file1,int print_arr[],int num,int li){
    int name1[50];
    int i=0,j=0,c1=0;
    for(i=0;i<num;i++){
        c1=0;
        for(j=0;j<num;j++){
            if(i!=j){
                if(strcmp(file1.name[print_arr[i]],file1.name[print_arr[j]])>0)
                    c1++;
            }
        }
        name1[c1]=i;
    }
    if(li>=file1.line1[name1[i]]){
        for(i=0;i<num;i++){
            for(j=0;j<file1.line1[name1[i]];j++)
                printf("%s\n",file1.data[name1[i]][j]);
        }
    }
    else{
        for(i=0;i<num;i++){
            for(j=0;j<li;j++)
                printf("%s\n",file1.data[name1[i]][j]);
        }
    }
}
void sort_file3(file_t file1,int print_arr[],int num,int li){
    int name1[50];
    int i=0,j=0,c1=0;
    for(i=0;i<num;i++){
        c1=0;
        for(j=0;j<num;j++){
            if(i!=j){
                if(strcmp(file1.name[print_arr[i]],file1.name[print_arr[j]])>0)
                    c1++;
            }
        }
        name1[c1]=i;
    }
    if(li>=file1.line1[name1[i]]){
        for(i=0;i<num;i++){
            for(j=0;j<file1.line1[name1[i]];j++)
                printf("%s\n",file1.data[name1[i]][j]);
        }
    }
    else{
        for(i=0;i<num;i++){
            for(j=file1.line1[name1[i]]-li;j<file1.line1[name1[i]];j++)
                printf("%s\n",file1.data[name1[i]][j]);
        }
    }
}
void print_file(file_t file1,char name[]){
    int i=0,j=0,c1=0;
    for(i=0;i<file1.file_num;i++){
        if(strcmp(file1.name[i],name)==0){
            for(j=0;j<file1.line1[i];j++)
                printf("%s\n",file1.data[i][j]);
        }
    }
}
void print_file2(file_t file1,char name[],int li){
    int i=0,j=0,c1=0;
    for(i=0;i<file1.file_num;i++){
        if(strcmp(file1.name[i],name)==0){
            if(li>=file1.line1[i]){
                for(j=0;j<file1.line1[i];j++)
                    printf("%s\n",file1.data[i][j]);
            }
            else{
                for(j=0;j<li;j++)
                    printf("%s\n",file1.data[i][j]);
            }
        }
    }
}
void print_file3(file_t file1,char name[],int li){
    int i=0,j=0,c1=0;
    for(i=0;i<file1.file_num;i++){
        if(strcmp(file1.name[i],name)==0){
            if(li>=file1.line1[i]){
                for(j=0;j<file1.line1[i];j++)
                    printf("%s\n",file1.data[i][j]);
            }
            else{
                for(j=file1.line1[i]-li-1;j<file1.line1[i];j++)
                    printf("%s\n",file1.data[i][j]);
            }
        }
    }
}
int vim_file(file_t *file1,char target[]){
    int i=0,j=0,line=0,tar=0,f1=1,s1=0;
    char tmp_text[50][50];
    char in1[50];
    for(i=0;i<50;i++){
        for(j=0;j<50;j++)
            tmp_text[i][j]='\0';
    }
    for(i=0;i<(*file1).file_num;i++){
        if(strcmp((*file1).name[i],target)==0){
            tar=i;
            break;
        }
    }
    while(1){
        for(i=0;i<50;i++)
            in1[i]='\0';
        gets(in1);
        i=0;
        if((in1[0]=='a')&&(s1==0)){
            s1=1;
            while(in1[i]!='\0'){
                in1[i]=in1[i+1];
                i++;
            }
            if(strlen(in1)>0){
                strcpy(tmp_text[line],in1);
                line++;
            }
        }
        else if((in1[0]!=':')&&(s1==1)){
            strcpy(tmp_text[line],in1);
            line++;
        }
        else if(strcmp(in1,":w")==0){
            f1=0;
            for(i=0;i<line;i++){
                strcpy((*file1).data[tar][i],tmp_text[i]);
            }
            (*file1).line1[tar]=line;
        }
        else if(strcmp(in1,":q")==0){
            if(f1==1)
                printf("error\n");
            break;
        }
        else if(strcmp(in1,":q!")==0){
            break;
        }
        else if(strcmp(in1,":wq")==0){
            f1=0;
            for(i=0;i<line;i++){
                strcpy((*file1).data[tar][i],tmp_text[i]);
            }
            (*file1).line1[tar]=line;
            break;
        }
    }
    return tar;
}
void remove_file(file_t *file1,int t1){
    int i=0,j=0;
    (*file1).line1[t1]=0;
    for(i=0;i<20;i++)
        (*file1).name[t1][i]='\0';
    for(i=0;i<50;i++){
        for(j=0;j<50;j++)
            (*file1).data[t1][i][j]='\0';
    }
}
int judge_str(char start[],char end[],int len,char word[]){
    int i=0,c1=0;
    if(end==NULL){
        for(i=0;i<strlen(start);i++){
            if(word[i]!=start[i])
                break;
        }
        if(i==strlen(start))
            c1++;
        if(strlen(word)>=len)
            c1++;
    }
    else if(start==NULL){
        for(i=strlen(end);i>=0;i--){
            if(word[strlen(word)-strlen(end)+i]!=end[i])
                break;
        }
        if(i==-1)
            c1++;
        if(strlen(word)>=len)
            c1++;
    }
    if(c1==2)
        return 1;
    return 0;

}
int main(){
    int i=0,j=0,n=0,c1=0,c2=0,len=0,print_arr[50];
    char in[50];
    char *word1[10];
    char *search[2];
    file_t file_all;
    file_all.file_num=0;
    while(1){
        for(i=0;i<50;i++)
            in[i]='\0';
        /*for(i=0;i<10;i++)
            word1[i]=NULL;*/
        c1=c2=0;
        gets(in);
        n=mystrtok(in,word1);
        len=strlen(word1[1]);
        if(strcmp(word1[0],"touch")==0){
            for(i=1;i<n;i++){
                strcpy(file_all.name[file_all.file_num],word1[i]);
                file_all.file_num++;
            }
        }
        else if(strcmp(word1[0],"vim")==0){
            c1=vim_file(&file_all,word1[1]);
        }
        else if(strcmp(word1[0],"cat")==0){
            if(strstr(word1[1],"*")!=0){
                if(word1[1][0]=='*'){
                    search[0]=NULL;
                    search[1]=word1[1]+1;
                }
                else if(word1[1][strlen(word1[1])-1]=='*'){
                    search[0]=word1[1];
                    word1[1][strlen(word1[1])-1]='\0';
                    search[1]=NULL;
                }
                for(i=0;i<file_all.file_num;i++){
                    c1=judge_str(search[0],search[1],len,file_all.name[i]);
                    if(c1==1){
                        print_arr[c2]=i;
                        c2++;
                    }
                }
                sort_file(file_all,print_arr,c2);
            }
            else{
                for(i=1;i<n;i++)
                    print_file(file_all,word1[i]);
            }
        }
        else if(strcmp(word1[0],"head")==0){
            if(strstr(word1[1],"*")!=0){
                if(word1[1][0]=='*'){
                    search[0]=NULL;
                    search[1]=word1[1]+1;
                }
                else if(word1[1][strlen(word1[1])-1]=='*'){
                    search[0]=word1[1];
                    word1[1][strlen(word1[1])-1]='\0';
                    search[1]=NULL;
                }
                for(i=0;i<file_all.file_num;i++){
                    c1=judge_str(search[0],search[1],len,file_all.name[i]);
                    if(c1==1){
                        print_arr[c2]=i;
                        c2++;
                    }
                }
                sort_file2(file_all,print_arr,c2,10);
            }
            else if(strcmp(word1[1],"-n")!=0){
                for(i=1;i<n;i++)
                    print_file2(file_all,word1[i],10);
            }
            if(strstr(word1[3],"*")!=0){
                if(word1[3][0]=='*'){
                    search[0]=NULL;
                    search[1]=word1[3]+1;
                }
                else if(word1[3][strlen(word1[3])-1]=='*'){
                    search[0]=word1[3];
                    word1[3][strlen(word1[3])-1]='\0';
                    search[1]=NULL;
                }
                for(i=0;i<file_all.file_num;i++){
                    c1=judge_str(search[0],search[1],len,file_all.name[i]);
                    if(c1==1){
                        print_arr[c2]=i;
                        c2++;
                    }
                }
                sort_file2(file_all,print_arr,c2,word1[2][0]-'0');
            }
            else if(strcmp(word1[1],"-n")==0){
                for(i=3;i<n;i++)
                    print_file2(file_all,word1[i],word1[2][0]-'0');
            }

        }
        else if(strcmp(word1[0],"tail")==0){
            if(strstr(word1[1],"*")!=0){
                if(word1[1][0]=='*'){
                    search[0]=NULL;
                    search[1]=word1[1]+1;
                }
                else if(word1[1][strlen(word1[1])-1]=='*'){
                    search[0]=word1[1];
                    word1[1][strlen(word1[1])-1]='\0';
                    search[1]=NULL;
                }
                for(i=0;i<file_all.file_num;i++){
                    c1=judge_str(search[0],search[1],len,file_all.name[i]);
                    if(c1==1){
                        print_arr[c2]=i;
                        c2++;
                    }
                }
                sort_file3(file_all,print_arr,c2,10);
            }
            else if(strcmp(word1[1],"-n")!=0){
                for(i=1;i<n;i++)
                    print_file3(file_all,word1[i],10);
            }
            if(strstr(word1[3],"*")!=0){
                if(word1[3][0]=='*'){
                    search[0]=NULL;
                    search[1]=word1[3]+1;
                }
                else if(word1[3][strlen(word1[3])-1]=='*'){
                    search[0]=word1[3];
                    word1[3][strlen(word1[3])-1]='\0';
                    search[1]=NULL;
                }
                for(i=0;i<file_all.file_num;i++){
                    c1=judge_str(search[0],search[1],len,file_all.name[i]);
                    if(c1==1){
                        print_arr[c2]=i;
                        c2++;
                    }
                }
                sort_file3(file_all,print_arr,c2,word1[2][0]-'0');
            }
            else if(strcmp(word1[1],"-n")==0){
                for(i=3;i<n;i++)
                    print_file3(file_all,word1[i],word1[2][0]-'0');
            }
        }
        else if(strcmp(word1[0],"rm")==0){
            for(i=1;i<n;i++){
                for(j=0;j<file_all.file_num;j++){
                    if(strcmp(file_all.name[j],word1[i])==0)
                        remove_file(&file_all,j);
                }
            }
        }
        else if(strcmp(word1[0],"ls")==0){
            for(i=0;i<file_all.file_num;i++){
                if(file_all.name[i][0]!='\0')
                    printf("%s ",file_all.name[i]);
            }
            printf("\n");
        }
        else if(strcmp(word1[0],"exit")==0)
            break;
    }
    return 0;
}
