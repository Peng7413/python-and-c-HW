#include <stdio.h>
int choose_road(int list_city[10][10],int n,int m,int x,int y,int *min,int now,int map_point[10][10]){
    int i=0,j=0,next=0;
    int new_map_point[10][10];
    now+=list_city[y][x];
    next=now;
    map_point[y][x]=1;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++)
            new_map_point[i][j]=map_point[i][j];
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            printf("%d ",map_point[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("%d %d\n",y,x);
    printf("%d %d\n\n",*min,next);
    if(now>*(min))
        return 0;
    if((x==m-1)&&(y==n-1)){
        map_point[m-1][n-1]=0;
        if(now<=*(min))
            *min=now;
        return 0;
    }
    if((x+1<m)&&(map_point[y][x+1]!=1)){
        choose_road(list_city,n,m,x+1,y,min,next,new_map_point);
        new_map_point[y][x+1]=0;
    }
    if((y+1<n)&&(map_point[y+1][x]!=1)){
        choose_road(list_city,n,m,x,y+1,min,next,new_map_point);
        new_map_point[y+1][x]=0;
    }
    if((x-1>=0)&&(map_point[y][x-1]!=1)){
        choose_road(list_city,n,m,x-1,y,min,next,new_map_point);
        new_map_point[y][x-1]=0;
    }
    if((y-1>=0)&&(map_point[y-1][x]!=1)){
        choose_road(list_city,n,m,x,y-1,min,next,new_map_point);
        new_map_point[y-1][x]=0;
    }
}
int main(){
    int i=0,j=0,n=0,m=0;
    int list_city[10][10]={0};
    int best_road=0;
    int map_point[10][10]={0};
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&list_city[i][j]);
            best_road+=list_city[i][j];
        }
    }
    choose_road(list_city,n,m,0,0,&best_road,0,map_point);
    printf("%d",best_road);
    return 0;
}
