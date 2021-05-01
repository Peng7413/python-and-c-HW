#include <stdio.h>
int bingo_remove(int n,int list_num[n][n],int choose_num){
    int i=0,j=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(list_num[i][j]==choose_num){
                list_num[i][j]=-1;
                return 0;
            }
        }
    }
}
int cal_line(int n,int list_num[n][n]){
    int i=0,j=0,c1=0,c2=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(list_num[i][j]==-1)
                c1++;
        }
        if(c1==n)
            c2++;
        c1=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(list_num[j][i]==-1)
                c1++;
        }
        if(c1==n)
            c2++;
        c1=0;
    }
    for(i=0;i<n;i++){
        if(list_num[i][i]==-1)
            c1++;
    }
    if(c1==n)
        c2++;
    c1=0;
    for(i=0;i<n;i++){
        if(list_num[n-1-i][i]==-1)
            c1++;
    }
    if(c1==n)
        c2++;
    return c2;
}
int main(){
    int n=0,i=0,j=0,player1_line=0,player2_line=0;
    char c;
    scanf("%d",&n);
    int player1[n][n],player2[n][n];
    int list_num[n*n];
    for(i=0;i<n*n;i++)
            list_num[i]=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            scanf("%d",&player1[i][j]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            scanf("%d",&player2[i][j]);
    }
    i=0;
    while(c!='\n'){
        scanf("%d%c",&list_num[i],&c);
        i++;
    }
    i=0;
    while(list_num[i]!=0){
        bingo_remove(n,player1,list_num[i]);
        bingo_remove(n,player2,list_num[i]);
        i++;
    }
    player1_line=cal_line(n,player1);
    player2_line=cal_line(n,player2);
    if(player1_line<player2_line)
        printf("Player2 wins %d, Player1 loses %d ",player2_line,player1_line);
    else if(player1_line>player2_line)
        printf("Player1 wins %d, Player2 loses %d ",player1_line,player2_line);
    else if(player1_line==player2_line)
        printf("Draw %d",player2_line);
    return 0;
}
