#include <stdio.h>
#include <math.h>
int main(){
    double a=0.0,b=0.0,c=0.0,x1=0.0,x2=0.0,T=0.0,c1=0.0;
    scanf("%lf",&a);
    scanf("%lf",&b);
    scanf("%lf",&c);
    T=b*b-4*a*c;
    if(T>=0){
        x1=(-b+sqrt(T))/(2*a);
        x2=(-b-sqrt(T))/(2*a);
        if(x1>0){
            c1 = floor(x1*10);
        }
        else{
            c1 = ceil(x1*10);
        }
        c1 = x1*10-c1;
        c1 = c1*0.1;
        x1 = x1-c1;
        if(x2>0){
            c1 = floor(x2*10);
        }
        else{
            c1 = ceil(x2*10);
        }
        c1 = x2*10-c1;
        c1 = c1*0.1;
        x2 = x2-c1;
        printf("%.1lf\n",x1);
        printf("%.1lf",x2);
    }
    else{
        x1= -b/(2*a);
        x2= -b/(2*a);
        if(a<0){
            a = -a;
        }
        T=sqrt(-T)/(2*a);
        if(x1>0){
            c1 = floor(x1*10);
        }
        else{
            c1 = ceil(x1*10);
        }
        c1 = x1*10-c1;
        c1 = c1*0.1;
        x1 = x1-c1;
        if(x2>0){
            c1 = floor(x2*10);
        }
        else{
            c1 = ceil(x2*10);
        }
        c1 = x2*10-c1;
        c1 = c1*0.1;
        x2 = x2-c1;
        if(T>0){
            c1 = floor(T*10);
        }
        else{
            c1 = ceil(T*10);
        }
        c1 = T*10-c1;
        c1 = c1*0.1;
        T = T-c1;
        printf("%.1lf+%.1lfi\n",x1,T);
        printf("%.1lf-%.1lfi",x2,T);

    }
    return 0;
}

