#include <stdio.h>

int isPrime(int n){
    int i=0,x1=0,x2=0;
    for(i=1;i<=n;i++){
        x1=n%i;
        if(x1==0){
            x2=x2+1;
        }
    }
    if(x2==2){
        return 1;
    }
    else{
        return 0;
    }
}
int stair(int n){
    int i=0,c1=1;
    for(i=1;i<=n;i++){
        c1=c1*i;
    }
    return c1;
}

int main(){
    int i=0,input=0,f1=0,x1=0,x2=0,x3=0;
    char c;
    scanf("%d",&input);
    while(((c = getchar()) != EOF) && (c != '\n')){
            f1=1;
    }
    if((input<0)||(input>=1000)){
        f1=1;
    }
    if(f1==1){
        printf("E");
    }
    else{
        for(i=2;i<=input;i++){
        x3=isPrime(i);
        if((x3==1)&&(input%i==0)){
            x1=stair(i);
            printf("%d,%d\n",i,x1);
            x2=x2+x1;
        }
        }
        printf("%d",x2);
        }
    return 0;
}

