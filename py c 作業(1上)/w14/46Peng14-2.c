#include<stdio.h>
void compute(int x1, int y1, int x2, int y2, int *perimeter, int *area){
    int c1=1,c2=0;
    if(x1>x2){
        c1=c1*(x1-x2);
        c2=c2+((x1-x2)*2);
    }
    else{
        c1=c1*(x2-x1);
        c2=c2+((x2-x1)*2);
    }
    if(y1>y2){
        c1=c1*(y1-y2);
        c2=c2+((y1-y2)*2);
    }
    else{
        c1=c1*(y2-y1);
        c2=c2+((y2-y1)*2);
    }
    if(c2>(*perimeter)){
        *perimeter=c2;
    }
    if(c1>(*area)){
        *area=c1;
    }
}
int main(){
    int x1=0,y1=0,x2=0,y2=0,result1=0,result2=0,f1=0;
    while(1){
        scanf("%d",&x1);
        if(x1==-1){
            break;
        }
        scanf("%d%d%d",&y1,&x2,&y2);
        if((x1==x2)||(y1==y2)){
            f1=1;
            break;
        }
        compute(x1,y1,x2,y2,&result1,&result2);
    }
    if(f1==1){
        printf("Error");
    }
    else{
        printf("%d\n",result2);
        printf("%d\n",result1);
    }
    return 0;
}
