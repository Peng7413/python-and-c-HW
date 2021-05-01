#include <stdio.h>
void add(int list1[],int list2[],int dot1){
    int i=0,x1=0;
    int list_result[100];
    for(i=0;i<100;i++){
        list_result[i]=list1[i];
    }
    for(i=99;i>=0;i--){
        if(list_result[i]+list2[i]>=10){
            list_result[i-1]=list_result[i-1]+(list_result[i]+list2[i])/10;
            list_result[i]=(list_result[i]+list2[i])%10;
        }
        else{
            list_result[i]=list_result[i]+list2[i];
        }
    }
    for(i=0;i<100;i++){
        if((list_result[i]==0)&&(i!=100-dot1-1)){
            x1+=1;
        }
        else{
            break;
        }
    }
    for(i=99;i>=0;i--){
        if(list_result[i]==0)
            list_result[i]=-1;
        else
            break;
    }
    for(i=x1;i<100;i++){
        if(i==100-dot1)
            printf(".");
        if(list_result[i]!=-1)
            printf("%d",list_result[i]);
    }
    printf("\n");
}

void miuns(int list1[],int list2[],int dot1){
    int i=0,x1=0;
    int list_result[100];
    for(i=0;i<100;i++){
        list_result[i]=list1[i];
    }
    for(i=99;i>=0;i--){
        if(list_result[i]-list2[i]<0){
            list_result[i-1]=list_result[i-1]-1;
            list_result[i]=list_result[i]-list2[i]+10;
        }
        else{
            list_result[i]=list_result[i]-list2[i];
        }
    }
    for(i=0;i<100;i++){
        if((list_result[i]==0)&&(i!=100-dot1-1)){
            x1+=1;
        }
        else{
            break;
        }
    }
    for(i=99;i>=0;i--){
        if(list_result[i]==0)
            list_result[i]=-1;
        else
            break;
    }
    for(i=x1;i<100;i++){
        if(i==100-dot1)
            printf(".");
        if(list_result[i]!=-1)
            printf("%d",list_result[i]);
    }
    printf("\n");
}
void multiply(int list1[],int list2[],int dot1){
    int i=0,j=0,x1=0;
    int list_result[100];
    for(i=0;i<100;i++){
        list_result[i]=0;
    }
    for(i=99;i>=0;i--){
        for(j=99;j>=0;j--){
            list_result[j-(99-i)]+=(list1[j]*list2[i]);
        }
        for(j=99;j>=0;j--){
            if(list_result[j]>=10){
                list_result[j-1]=list_result[j-1]+(list_result[j])/10;
                list_result[j]=(list_result[j])%10;
            }
        }
    }
    for(i=0;i<100;i++){
        if((list_result[i]==0)&&(i!=100-dot1*2-1)){
            x1+=1;
        }
        else{
            break;
        }
    }
    for(i=99;i>=0;i--){
        if(list_result[i]==0)
            list_result[i]=-1;
        else
            break;
    }
    for(i=x1;i<100;i++){
        if(i==100-dot1*2)
            printf(".");
        if(list_result[i]!=-1)
            printf("%d",list_result[i]);
    }
    printf("\n");
}
void decide_miuns(int c1,int c2,int list1[],int list2[],int dot1,int f1){
    int i=0;
    if(c1<c2){
        printf("-");
        miuns(list2,list1,dot1);
    }
    else if(c1>c2){
        miuns(list1,list2,dot1);
    }
    else{
        for(i=0;i<100;i++){
            if(list1[i]>list2[i]){
                miuns(list1,list2,dot1);
                f1=1;
                break;
            }
            else if(list1[i]<list2[i]){
                printf("-");
                miuns(list2,list1,dot1);
                f1=1;
                break;
            }
        }
        if(f1==0){
            printf("0\n");
        }
    }
}
int main(){
    char list1_in[100],list2_in[100];
    int list1[100],list2[100];
    int i=0,c1=0,c2=0,c3=0,j=0,f1=0,dot1=0,dot2=0;
    int s1=0,s2=0;
    for(i=0;i<100;i++){
        list1_in[i]='a';
        list2_in[i]='a';
        list1[i]=0;
        list2[i]=0;
    }
    scanf("%s",list1_in);
    scanf("%s",list2_in);
    if(list1_in[0]=='-'){
        s1=1;
        for(i=0;i<99;i++){
            list1_in[i]=list1_in[i+1];
        }
    }
    if(list2_in[0]=='-'){
        s2=1;
        for(i=0;i<99;i++){
            list2_in[i]=list2_in[i+1];
        }
    }
    for(i=0;i<100;i++){
        if(list1_in[i]=='.')
            dot1=i;
        if(list1_in[i]=='a')
            break;
        c1=i;
    }
    dot1=c1-dot1-1;
    for(i=0;i<100;i++){
        if(list2_in[i]=='.')
            dot2=i;
        if(list2_in[i]=='a')
            break;
        c2=i;
    }
    dot2=c2-dot2-1;
    if(dot1<dot2){
        for(i=c1;i<c1+(dot2-dot1);i++){
            list1_in[i]='0';
        }
        c1=c1+(dot2-dot1);
        dot1=dot2;
    }
    else if(dot2<dot1){
        for(i=c2;i<c2+(dot1-dot2);i++){
            list2_in[i]='0';
        }
        c2=c2+(dot1-dot2);
        dot2=dot1;
    }
    for(i=99;i>=100-c1;i--){
        if(list1_in[i-(100-c1)]!='.')
            list1[i+c3]=(int)list1_in[i-(100-c1)]-48;
        else
            c3=1;
    }
    c3=0;
    for(i=99;i>=100-c2;i--){
        if(list2_in[i-(100-c2)]!='.')
            list2[i+c3]=(int)list2_in[i-(100-c2)]-48;
        else
            c3=1;
    }
    if((s1==0)&&(s2==0)){
        add(list1,list2,dot1);
        decide_miuns(c1,c2,list1,list2,dot1,f1);
        multiply(list1,list2,dot1);
    }
    else if((s1==0)&&(s2==1)){
        decide_miuns(c1,c2,list1,list2,dot1,f1);
        add(list1,list2,dot1);
        printf("-");
        multiply(list1,list2,dot1);
    }
    else if((s1==1)&&(s2==0)){
        decide_miuns(c2,c1,list2,list1,dot1,f1);
        printf("-");
        add(list1,list2,dot1);
        printf("-");
        multiply(list1,list2,dot1);
    }
    else if((s1==1)&&(s2==1)){
        printf("-");
        add(list1,list2,dot1);
        decide_miuns(c2,c1,list2,list1,dot1,f1);
        multiply(list1,list2,dot1);
    }
    return 0;
}
