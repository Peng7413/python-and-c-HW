#include <stdio.h>
#include <math.h>
void draw4_in5(double *n){
    double c1=0;
    c1=floor(*n*1000)/10;
    c1=round(c1)/100;
    *n=c1;
}
void rank(double list1[],int *c2,int n){
    int i=0;
    double c1=0;
    c1=list1[0];
    *c2=0;
    for(i=0;i<n;i++){
        if(c1<list1[i]){
            c1=list1[i];
            *c2=i;
        }
    }
}
int main(){
    char name[20][20],course_name[20][20][20];
    int i=0,n=0,j=0,k=0,course_num=0;
    int c1=0,f1=1;
    int score[20][20],id[20],learn_num[20][20],list_course_num[20]={0};
    int list_realrank[20]={0},list_reallearn_num[20]={0};
    double list_average[20]={0},list_average2[20]={0},list_rank[20]={0};
    int c3=0,c2=0,x1=0,x2=0;
    for(i=0;i<20;i++){
        id[i]=0;
    }
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
        name[i][j]='0';
        learn_num[i][j]=0;
        }
    }
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
        score[i][j]=0;
        }
    }
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            for(k=0;k<20;k++){
                course_name[i][j][k]='0';
            }
        }
    }
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %s",&id[i],&name[i]);
        scanf("%d",&course_num);
        list_course_num[i]=course_num;
        for(j=0;j<course_num;j++){
            scanf("%s %d %d",&course_name[i][j],&learn_num[i][j],&score[i][j]);
        }
    }
    for(i=0;i<n;i++){
        c3=0;
        for(j=0;j<20;j++){
            list_average[i]+=(score[i][j]*learn_num[i][j]);
            c3+=learn_num[i][j];
            if(score[i][j]>=60){
                list_reallearn_num[i]+=learn_num[i][j];
            }
        }
        list_average[i]=list_average[i]/c3;
        draw4_in5(&list_average[i]);
        list_average2[i]=list_average[i];
    }
    for(i=1;i<n+1;i++){
        rank(list_average,&c2,n);
        list_rank[n-i]=list_average[c2];
        if(list_rank[n-i+1]==list_average[c2]){
            list_realrank[c2]=x1;
        }
        else{
            x1=i;
            list_realrank[c2]=x1;
        }
        list_average[c2]=-100;
    }
    while(1){
        f1=1;
        scanf("%d",&c1);
        if(c1==0){
            break;
        }
        else{
            for(i=0;i<20;i++){
                if(c1==id[i]){
                    printf("%d ",id[i]);
                    for(j=0;j<20;j++){
                        if((int)name[i][j]==0){
                            break;
                        }
                        printf("%c",name[i][j]);
                    }
                    printf("\n");
                    for(j=0;j<list_course_num[i];j++){
                        for(k=0;k<20;k++){
                            if((int)course_name[i][j][k]==0){
                                break;
                            }
                            printf("%c",course_name[i][j][k]);
                        }
                        printf(" %d %d\n",learn_num[i][j],score[i][j]);
                    }
                    printf("%d\n",list_reallearn_num[i]);
                    printf("%.2f\n",list_average2[i]);
                    printf("%d\n",list_realrank[i]);
                    f1=0;
                }
            }
            if(f1==1){
                printf("ERROR\n");
            }
        }
    }
    return 0;
}
