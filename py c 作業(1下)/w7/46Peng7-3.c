#include <stdio.h>
int deal_event(int list_hour[],int list1[][3],int index1,int n){
    int i=0;
    for(i=list1[index1][1];i<list1[index1][2];i++){
        if(list_hour[i]<=n)
            list_hour[i]+=1;
        if(list_hour[i]>n)
            return -1;
    }
    return list1[index1][2]-list1[index1][1];
}
int cal_hour(int list1[][3],int list_com[],int n,int center){
    int list_hour[24]={0};
    int i=0,j=0,total_hour=0,c1=0;
    while(list_com[i]!=0){
        for(j=0;j<n;j++){
            if(list1[j][0]==list_com[i]){
                c1=deal_event(list_hour,list1,j,center);
            }
        }
        if(c1==-1)
            return 0;
        else
            total_hour+=c1;
        i++;
    }
    return total_hour;
}
int check(int list1[],int n,int element){
    int i=0;
    for(i=0;i<element;i++){
        if(list1[i]==n)
            return 1;
    }
    return 0;
}
void combine1(int list1[][3],int limit,int element,int combine_now[10],int *re,int *re2,int center){
    int i=0,j=0,c1=0;
    int combine_next[10]={0};
    for(i=0;i<10;i++)
        combine_next[i]=combine_now[i];
    if(limit<element){
        for(i=0;i<element;i++){
            if(check(combine_next,list1[i][0],element)==0){
                combine_next[limit]=list1[i][0];
                c1=cal_hour(list1,combine_next,element,center);
                if(c1>*re)
                    *re=c1;
                if((limit+1>*re2)&&(c1!=0))
                    *re2=limit+1;
                combine1(list1,limit+1,element,combine_next,re,re2,center);
            }
        }
    }
}
int main(){
    int i=0,j=0,n=0,result1=0,result_event=0;
    int meeting_center=0;
    scanf("%d",&meeting_center);
    scanf("%d",&n);
    int event_num[n][3];
    int event_num2[n];
    int list_empty[10]={0};
    for(i=0;i<n;i++)
        scanf("%d %d %d",&event_num[i][0],&event_num[i][1],&event_num[i][2]);
    for(i=0;i<n;i++)
        event_num2[i]=event_num[i][0];
    combine1(event_num,0,n,list_empty,&result1,&result_event,meeting_center);
    printf("%d\n",result1);
    printf("%d\n",result_event);
    return 0;
}
