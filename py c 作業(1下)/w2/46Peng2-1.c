#include <stdio.h>
#include <math.h>
void draw4_in5(double *n){
    double c1=0;
    c1=floor(*n*1000)/10;
    c1=round(c1)/100;
    *n=c1;
}
void rank(int list1[],int *c2,int n){
    int c1=0,i=0;
    c1=list1[0];
    *c2=0;
    for(i=0;i<n;i++){
        if(c1<list1[i]){
            c1=list1[i];
            *c2=i;
        }
    }
}
void dio(char name[100][100],int score[100][3],int id[100],int n){
    int list_add[100]={0};
    double list_average[100]={0},list_rank[100]={0},c3=0,c4=0,c5=0,c6=0;
    int i=0,j=0,c2=0,x1=0,x2=0;
    int central1=0,central2=0;
    for(i=0;i<n;i++){
        list_add[i]=score[i][0]+score[i][1]+score[i][2];
        list_average[0]+=score[i][0];
        list_average[1]+=score[i][1];
        list_average[2]+=score[i][2];
    }
    c4=(list_average[0]+list_average[1]+list_average[2])/n;
    draw4_in5(&c4);
    list_average[0]=list_average[0]/n;
    list_average[1]=list_average[1]/n;
    list_average[2]=list_average[2]/n;
    for(i=1;i<n+1;i++){
        rank(list_add,&c2,n);
        printf("%d ",id[c2]);
        for(j=0;j<100;j++){
            if((int)name[c2][j]==0){
                break;
            }
            printf("%c",name[c2][j]);
        }
        printf(" ");
        list_rank[n-i]=list_add[c2];
        if(list_rank[n-i+1]==list_add[c2]){
            printf("%d %d %d %d %d\n",score[c2][0],score[c2][1],score[c2][2],list_add[c2],x1);
        }
        else{
            x1=i;
            printf("%d %d %d %d %d\n",score[c2][0],score[c2][1],score[c2][2],list_add[c2],i);
        }
        list_add[c2]=-100;
    }
    for(i=0;i<3;i++){
        draw4_in5(&list_average[i]);
    }
    printf("%.2f\n",list_average[0]);
    printf("%.2f\n",list_average[1]);
    printf("%.2f\n",list_average[2]);
    printf("%.2f\n",c4);
    if(n%2!=0){
        central1=(n+1)/2-1;
        printf("%.2f\n",list_rank[central1]);

    }
    else{
        central1=n/2-1;
        central2=central1+1;
        printf("%.2f\n",(list_rank[central1]+list_rank[central2])/2);
    }
    for(i=0;i<n;i++){
        c3+=((list_rank[i]-c4)*(list_rank[i]-c4));
    }
    printf("%.2f\n",c3/n);
    c5=sqrt(c3/n);
    draw4_in5(&c5);
    printf("%.2f\n",c5);
    if(n%2!=0){
        for(i=n-1;i>=0;i--){
            if(list_rank[i]<=list_rank[central1]){
                continue;
            }
            c6+=list_rank[i];
            x2+=1;
        }
        c6=c6/x2;
        draw4_in5(&c6);
        printf("%.2f\n",c6);
        c6=0;
        x2=0;
        for(i=0;i<n;i++){
            if(list_rank[i]>=list_rank[central1]){
                continue;
            }
            c6+=list_rank[i];
            x2+=1;
        }
        c6=c6/x2;
        draw4_in5(&c6);
        printf("%.2f\n",c6);
    }
    else{
        for(i=n-1;i>=0;i--){
            if(list_rank[i]<=(list_rank[central1]+list_rank[central2])/2){
                continue;
            }
            c6+=list_rank[i];
            x2+=1;
        }
        c6=c6/x2;
        draw4_in5(&c6);
        printf("%.2f\n",c6);
        c6=0;
        x2=0;
        for(i=0;i<n;i++){
            if(list_rank[i]>=(list_rank[central1]+list_rank[central2])/2){
                continue;
            }
            c6+=list_rank[i];
            x2+=1;
        }
        c6=c6/x2;
        draw4_in5(&c6);
        printf("%.2f\n",c6);
    }
}

int main(){
    char name[100][100];
    int i=0,n=0,j=0;
    int score[100][3],id[100];
    for(i=0;i<100;i++){
        id[i]=0;
    }
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
        name[i][j]='0';
        }
    }
    for(i=0;i<100;i++){
        for(j=0;j<3;j++){
        score[i][j]=0;
        }
    }
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %s %d %d %d",&id[i],&name[i],&score[i][0],&score[i][1],&score[i][2]);
    }
    dio(name,score,id,n);
    return 0;
}
