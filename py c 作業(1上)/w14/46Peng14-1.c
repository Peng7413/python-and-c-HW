#include<stdio.h>
void simple1(int x1_n,int x2_d,int *x1_n_s,int *x2_d_s){
    int max_num=0;
    int *s1=x1_n_s,*s2=x2_d_s;
    while((x1_n!=0)&&(x2_d!=0)){
        if(x1_n>=x2_d){
            x1_n=x1_n%x2_d;
        }
        else{
            x2_d=x2_d%x1_n;
        }
    }
    if(x1_n>x2_d){
        max_num=x1_n;
    }
    else{
        max_num=x2_d;
    }
    *s1=*s1/max_num;
    *s2=*s2/max_num;
}
int simple2(int x1_n,int x2_d,int *x1_d_s){
    int result=0;
    if(x1_n>=x2_d){
    result=(x1_n-(x1_n%x2_d))/x2_d;
    *x1_d_s=x1_n%x2_d;
    }
    return result;
}
void add(int n1,int d1,int n2,int d2){
    int n_add=0,d_add=0,mixnum_add=0,minus_rotation=0;
    int *n_add_s=&n_add,*d_add_s=&d_add;
    d_add=d1*d2;
    n_add=n1*d2+n2*d1;
    if(n_add<0){
        n_add=-n_add;
        minus_rotation=1;
    }
    simple1(n_add,d_add,n_add_s,d_add_s);
    mixnum_add=simple2(n_add,d_add,n_add_s);
    if(minus_rotation==1){
        n_add=-n_add;
    }
    if(mixnum_add==0){
        printf("%d/%d\n",n_add,d_add);
    }
    else{
        if(n_add==0){
            printf("%d\n",mixnum_add);
        }
        else{
            printf("%d(%d/%d)\n",mixnum_add,n_add,d_add);
        }
    }
}
void multiply(int n1,int d1,int n2,int d2){
    int n_mult=0,d_mult=0,mixnum_mult=0,minus_rotation=0;
    int *n_mult_s=&n_mult,*d_mult_s=&d_mult;
    d_mult=d1*d2;
    n_mult=n1*n2;
    if(n_mult<0){
        n_mult=-n_mult;
        minus_rotation=1;
    }
    simple1(n_mult,d_mult,n_mult_s,d_mult_s);
    mixnum_mult=simple2(n_mult,d_mult,n_mult_s);
    if(minus_rotation==1){
        n_mult=-n_mult;
    }
    if(mixnum_mult==0){
        printf("%d/%d\n",n_mult,d_mult);
    }
    else{
        if(n_mult==0){
            printf("%d\n",mixnum_mult);
        }
        else{
            printf("%d(%d/%d)\n",mixnum_mult,n_mult,d_mult);
        }
    }
}
int main(){
    int n1=0,d1=0,n2=0,d2=0,f1=0;
    scanf("%d/%d",&n1,&d1);
    scanf("%d/%d",&n2,&d2);
    if((n1==0)||(n2==0)||(d1==0)||(d2==0)){
        printf("ERROR\n");
        printf("ERROR\n");
        f1=1;
    }
    if(f1==0){
        add(n1,d1,n2,d2);
        multiply(n1,d1,n2,d2);
    }
return 0;
}
