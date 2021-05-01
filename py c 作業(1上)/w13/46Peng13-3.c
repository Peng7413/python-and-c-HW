#include <stdio.h>
void transfrom(int x1,int x2){
    int i=0,x3=0,x4=0,result[1000];
    for(i=0;i<1000;i++){
        result[i]=0;
    }
    i=0;
    while(x1>=x2){
        x3=x1%x2;
        x1=(x1-x3)/x2;
        result[i]=x3;
        i=i+1;
    }
    result[i]=x1;
    for(i=i;i>=0;i--){
        printf("%X",result[i]);
    }
}
int main(){
    int i=0,base=0,num=0,f1=0,x1=0,x2=0;
    scanf("%d %d",&base,&num);
    if((base<2)||(base>16)){
        f1=1;
    }
    if((num<0)||(num>1000000000)){
        f1=1;
    }
    if(f1==0){
        transfrom(num,base);
    }
    else{
        printf("E");
    }
    return 0;
}
