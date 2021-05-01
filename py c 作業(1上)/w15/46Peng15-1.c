#include<stdio.h>
void ko_no_dio_da(int x1[10][10],int *x2){
    int i=0,j=0,k=0;
    int c1=0,c2=0,c3=0;
    int data[]={5,5,5,5,5};
    for(i=0;i<10;i++){
        for(j=0;j<6;j++){
            int data[]={5,5,5,5,5};
            c1=0,c2=0;
            for(k=0;k<5;k++){
                data[k]=x1[i][j+k];
                c1+=x1[i][j+k];
                if(x1[i][j+k]==0){
                    c2=k;
                }
            }
            if(c1==4){
                c3=i*10+j+c2;
                *(x2+c3)=c3;
            }
        }
    }
}
void ko_no_dio_da2(int x1[10][10],int *x2){
    int i=0,j=0,k=0;
    int c1=0,c2=0,c3=0;
    int data[]={5,5,5,5,5};
    for(i=0;i<10;i++){
        for(j=0;j<6;j++){
            int data[]={5,5,5,5,5};
            c1=0,c2=0;
            for(k=0;k<5;k++){
                data[k]=x1[j+k][i];
                c1+=x1[j+k][i];
                if(x1[j+k][i]==0){
                    c2=k;
                }
            }
            if(c1==4){
                c3=(j+c2)*10+i;
                *(x2+c3)=c3;
            }
        }
    }
}
void ko_no_dio_da3(int x1[10][10],int *x2){
    int i=0,j=0,k=0;
    int c1=0,c2=0,c3=0;
    int data[]={5,5,5,5,5};
    for(i=0;i<6;i++){
        for(j=4;j<10;j++){
            int data[]={5,5,5,5,5};
            c1=0,c2=0;
            for(k=0;k<5;k++){
                data[k]=x1[i+k][j-k];
                c1+=x1[i+k][j-k];
                if(x1[i+k][j-k]==0){
                    c2=k;
                }
            }
            if(c1==4){
                c3=(i+c2)*10+j-c2;
                *(x2+c3)=c3;
            }
        }
    }
}

void ko_no_dio_da4(int x1[10][10],int *x2){
    int i=0,j=0,k=0;
    int c1=0,c2=0,c3=0;
    int data[]={5,5,5,5,5};
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            int data[]={5,5,5,5,5};
            c1=0,c2=0;
            for(k=0;k<5;k++){
                data[k]=x1[i+k][j+k];
                c1+=x1[i+k][j+k];
                if(x1[i+k][j+k]==0){
                    c2=k;
                }
            }
            if(c1==4){
                c3=(i+c2)*10+j+c2;
                *(x2+c3)=c3;
            }
        }
    }
}

int main(){
    int list_all[10][10],list_result[100];
    int i=0,j=0,x1=0,x2=0;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            scanf("%d",&list_all[i][j]);
        }
    }
    for(i=0;i<100;i++){
        list_result[i]=100;
    }
    ko_no_dio_da(list_all,list_result);
    ko_no_dio_da2(list_all,list_result);
    ko_no_dio_da3(list_all,list_result);
    ko_no_dio_da4(list_all,list_result);
    for(i=0;i<100;i++){
        if(list_result[i]!=100){
            x2=list_result[i]%10;
            x1=(list_result[i]-x2)/10;
            printf("%d %d\n",x1,x2);
        }
    }
    return 0;
}
