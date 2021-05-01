#include <stdio.h>
void add(int list1[10][10],int list2[10][10],int row,int col){
    int i=0,j=0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d ",list1[i][j]+list2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void minus(int list1[10][10],int list2[10][10],int row,int col){
    int i=0,j=0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d ",list1[i][j]-list2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void multiply(int list1[10][10],int list2[10][10],int row1_col2,int col1_row2){
    int i=0,j=0,k=0;
    int list_re1[10][10];
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            list_re1[i][j]=0;
        }
    }
    for(i=0;i<col1_row2;i++){
        for(j=0;j<row1_col2;j++){
            for(k=0;k<row1_col2;k++){
                list_re1[j][k]+=list1[j][i]*list2[i][k];
            }
        }
    }
    for(i=0;i<row1_col2;i++){
        for(j=0;j<row1_col2;j++){
            printf("%d ",list_re1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int list1[10][10],list2[10][10];
    int i=0,j=0,c1=0,c2=0;
    int row1,col1,row2,col2;
    scanf("%d %d",&row1,&col1);
    for(i=0;i<row1;i++){
        for(j=0;j<col1;j++){
            scanf("%d",&list1[i][j]);
        }
    }
    scanf("%d %d",&row2,&col2);
    for(i=0;i<row2;i++){
        for(j=0;j<col2;j++){
            scanf("%d",&list2[i][j]);
        }
    }
    if((row1==row2)&&(col1==col2)){
        add(list1,list2,row1,col1);
        minus(list1,list2,row1,col1);
    }
    else{
        printf("ERROR\n\n");
        printf("ERROR\n\n");
    }
    if((row1==col2)&&(col1==row2)){
        multiply(list1,list2,row1,col1);
    }
    else{
        printf("ERROR\n\n");
    }
    return 0;
}
