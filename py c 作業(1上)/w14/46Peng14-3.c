#include<stdio.h>
int ko_no_dio_da(int x1[9][9]){
    int check[9]={1,2,3,4,5,6,7,8,9};
    int data[9]={0,0,0,0,0,0,0,0,0};
    int i=0,j=0;
    int c1=0,c2=0;
    for(i=0;i<9;i++){
        int data[9]={0,0,0,0,0,0,0,0,0};
        c1=0;
        for(j=0;j<9;j++){
            data[x1[i][j]-1]=x1[i][j];
        }
        for(j=0;j<9;j++){
            if(check[j]==data[j]){
                c1+=1;
            }
        }
        if(c1==9){
            c2+=1;
        }
    }
    return c2;
}
int ko_no_dio_da2(int x1[9][9]){
    int check[9]={1,2,3,4,5,6,7,8,9};
    int data[9]={0,0,0,0,0,0,0,0,0};
    int i=0,j=0;
    int c1=0,c2=0;
    for(i=0;i<9;i++){
        int data[9]={0,0,0,0,0,0,0,0,0};
        c1=0;
        for(j=0;j<9;j++){
            data[x1[j][i]-1]=x1[j][i];
        }
        for(j=0;j<9;j++){
            if(check[j]==data[j]){
                c1+=1;
            }
        }
        if(c1==9){
            c2+=1;
        }
    }
    return c2;
}
int ko_no_dio_da3(int x1[9][9]){
    int check[9]={1,2,3,4,5,6,7,8,9};
    int data[9]={0,0,0,0,0,0,0,0,0};
    int i=0,j=0,k=0,l=0;
    int c1=0,c2=0;
    for(i=0;i<3;i++){
        for(l=0;l<3;l++){
        int data[9]={0,0,0,0,0,0,0,0,0};
        c1=0;
        for(j=0;j<3;j++){
            for(k=0;k<3;k++){
            data[x1[j+3*i][k+3*l]-1]=x1[j+3*i][k+3*l];
            }
        }
        for(j=0;j<9;j++){
            if(check[j]==data[j]){
                c1+=1;
            }
        }
        if(c1==9){
            c2+=1;
        }
        }
    }
    return c2;
}

int main(){
    int list_all[9][9];
    int i=0,j=0,x1=0,x2=0,x3=0;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            scanf("%d",&list_all[i][j]);
        }
    }
    x1=ko_no_dio_da(list_all);
    x2=ko_no_dio_da2(list_all);
    x3=ko_no_dio_da3(list_all);
    if((x1+x2+x3)==27){
        printf("Yes");
    }
    else{
        printf("No");
    }
return 0;
}
