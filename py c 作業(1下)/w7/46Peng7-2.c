#include <stdio.h>
#include <string.h>
void decimal_to_binary(int n,int length,char *binary){
    int i=10;
    char c1;
    char re[12]="00000000000";
    while(n/2>=1){
        c1=(n%2)+48;
        re[i]=c1;
        n=n/2;
        i--;
    }
    re[i]=n+48;
    length=i+1;
    for(i=0;i<12;i++)
        *(binary+i)=re[i];
}
int binary_to_decimal(const char* binary,int length){
    int i=0,result=0,position=1;
    for(i=length-2;i>=0;i--){
        if(i<length-2)
            position*=2;
        if(*(binary+i)=='1')
            result+=position;
    }
    return result;
}
int loopCircuit(int n){
    int i=0;
    if((n==0)||(n==1))
        return 0;
    else if(n%2==0)
        return loopCircuit(n/2)+1;
    else if(n%2==1)
        return loopCircuit((n+1)/2)+1;
}
int main(){
    int i=0,j=0,length=0,n=0,m=0;
    int result=0;
    char check1[2]="0",end1[3]="-1";
    char num_b[12]={'\0'},result_bin[10][12]={'\0'};
    while(1){
        scanf("%s",num_b);
        if(strcmp(num_b,end1)==0)
            break;
        if(strcmp(num_b,check1)!=0){
            length=strlen(num_b)+1;
            n=binary_to_decimal(num_b,length);
            for(i=0;i<=n;i++){
                result+=loopCircuit(i);
            }
            decimal_to_binary(result,1,result_bin[j]);
            result=0;
            j++;
        }
    }
    for(i=0;i<j;i++)
        printf("%s\n",result_bin[i]);
    return 0;
}
