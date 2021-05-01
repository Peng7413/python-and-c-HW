#include <stdio.h>
void add(int list1[],int list2[]){
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
        if(list_result[i]==0){
            x1+=1;
        }
        else{
            break;
        }
    }
    for(i=x1;i<100;i++){
        printf("%d",list_result[i]);
    }
    printf("\n");
}

void miuns(int list1[],int list2[]){
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
        if(list_result[i]==0){
            x1+=1;
        }
        else{
            break;
        }
    }
    for(i=x1;i<100;i++){
        printf("%d",list_result[i]);
    }
    printf("\n");
}
void multiply(int list1[],int list2[]){
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
        if(list_result[i]==0){
            x1+=1;
        }
        else{
            break;
        }
    }
    for(i=x1;i<100;i++){
        printf("%d",list_result[i]);
    }
    printf("\n");
}
int main(){
    char list1_in[100],list2_in[100];
    int list1[100],list2[100];
    int i=0,c1=0,c2=0,j=0,f1=0;
    for(i=0;i<100;i++){
        list1_in[i]='a';
        list2_in[i]='a';
        list1[i]=0;
        list2[i]=0;
    }
    scanf("%s",list1_in);
    scanf("%s",list2_in);
    for(i=0;i<100;i++){
        if(list1_in[i]=='a'){
            break;
        }
        c1=i;
    }
    for(i=0;i<100;i++){
        if(list2_in[i]=='a'){
            break;
        }
        c2=i;
    }
    for(i=99;i>=100-c1;i--){
        list1[i]=(int)list1_in[i-(100-c1)]-48;
    }
    for(i=99;i>=100-c2;i--){
        list2[i]=(int)list2_in[i-(100-c2)]-48;
    }
    add(list1,list2);
    if(c1<c2){
        printf("-");
        miuns(list2,list1);
    }
    else if(c1>c2){
        miuns(list1,list2);
    }
    else{
        for(i=0;i<100;i++){
            if(list1[i]>list2[i]){
                miuns(list1,list2);
                f1=1;
                break;
            }
            else if(list1[i]<list2[i]){
                printf("-");
                miuns(list2,list1);
                f1=1;
                break;
            }
        }
        if(f1==0){
            printf("0\n");
        }
    }
    multiply(list1,list2);
    return 0;
}
