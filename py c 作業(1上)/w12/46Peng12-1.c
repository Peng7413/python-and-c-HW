#include <stdio.h>
int check_courage(int x1,int ff){
    if(x1>10000){
        return 1;
    }
    else if(x1<1000){
        return 1;
    }
    else{
        return ff;
    }
}
int check_hour(int x2,int ff){
    if(x2>2){
        return 1;
    }
    else if(x2<1){
        return 1;
    }
    else{
        return ff;
    }
}
int check_day(int x3,int ff){
    if(x3>60){
        return 1;
    }
    else if(x3<10){
        return 1;
    }
    else if((x3%10)==0){
        return 1;
    }
    else{
        return ff;
    }
}
int check_Conflict(int cc1_num,int cc1_t,int cc1_d1,int cc1_d2,int cc2_num,int cc2_t,int cc2_d1,int cc2_d2,int ff){
    if(cc1_d1==cc2_d1){
    printf("%d,%d,%d\n",cc1_num,cc2_num,cc1_d1);
    ff=1;
    }
    if(cc1_d1==cc2_d2){
    printf("%d,%d,%d\n",cc1_num,cc2_num,cc1_d1);
    ff=1;
    }
    if(cc1_d2==cc2_d1){
    printf("%d,%d,%d\n",cc1_num,cc2_num,cc1_d2);
    ff=1;
    }
    if(cc1_d2==cc2_d2){
    printf("%d,%d,%d\n",cc1_num,cc2_num,cc1_d2);
    ff=1;
    }
    return ff;
    }

int main(){
    int c1_num=0,c1_t=0,c1_d1=0,c1_d2=0;
    int c2_num=0,c2_t=0,c2_d1=0,c2_d2=0;
    int c3_num=0,c3_t=0,c3_d1=0,c3_d2=0;
    int f1=0,f2=0;
    scanf("%d",&c1_num);
    scanf("%d",&c1_t);
    scanf("%d",&c1_d1);
    if(c1_t==2){
        scanf("%d",&c1_d2);
    }
    scanf("%d",&c2_num);
    scanf("%d",&c2_t);
    scanf("%d",&c2_d1);
    if(c2_t==2){
        scanf("%d",&c2_d2);
    }
    scanf("%d",&c3_num);
    scanf("%d",&c3_t);
    scanf("%d",&c3_d1);
    if(c3_t==2){
        scanf("%d",&c3_d2);
    }
    f1=check_courage(c1_num,f1);
    f1=check_courage(c2_num,f1);
    f1=check_courage(c3_num,f1);
    f1=check_hour(c1_t,f1);
    f1=check_hour(c2_t,f1);
    f1=check_hour(c3_t,f1);
    f1=check_day(c1_d1,f1);
    if(c1_d2!=0){
    f1=check_day(c1_d2,f1);
    }
    f1=check_day(c2_d1,f1);
    if(c2_d2!=0){
    f1=check_day(c2_d2,f1);
    }
    f1=check_day(c3_d1,f1);
    if(c3_d2!=0){
    f1=check_day(c3_d2,f1);
    }
    if(f1==0){
    f2=check_Conflict(c1_num,c1_t,c1_d1,c1_d2,c2_num,c2_t,c2_d1,c2_d2,f2);
    f2=check_Conflict(c1_num,c1_t,c1_d1,c1_d2,c3_num,c3_t,c3_d1,c3_d2,f2);
    f2=check_Conflict(c2_num,c2_t,c2_d1,c2_d2,c3_num,c3_t,c3_d1,c3_d2,f2);
    if(f2==0){
    printf("correct");
    }
    }
    else{
    printf("-1");
    }
    return 0;
}
