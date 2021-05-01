#include <stdio.h>
int choose_road(char list_plane[20][20],int n,int x,int y,int map_point[20][20]){
    int i=0,j=0;
    int new_map_point[20][20];
    map_point[y][x]=1;
    list_plane[y][x]='#';
    for(i=0;i<20;i++){
        for(j=0;j<20;j++)
            new_map_point[i][j]=map_point[i][j];
    }
    if((x==n-2)&&(y==n-2)){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%c ",list_plane[i][j]);
            }
        printf("\n");
        }
        return 0;
    }
    if((y+1<n-1)&&(map_point[y+1][x]!=1)&&(list_plane[y+1][x]=='0')){
        choose_road(list_plane,n,x,y+1,new_map_point);
        new_map_point[y+1][x]=0;
    }
    if((y-1>=1)&&(map_point[y-1][x]!=1)&&(list_plane[y-1][x]=='0')){
        choose_road(list_plane,n,x,y-1,new_map_point);
        new_map_point[y-1][x]=0;
    }
    if((x-1>=1)&&(map_point[y][x-1]!=1)&&(list_plane[y][x-1]=='0')){
        choose_road(list_plane,n,x-1,y,new_map_point);
        new_map_point[y][x-1]=0;
    }
    if((x+1<n-1)&&(map_point[y][x+1]!=1)&&(list_plane[y][x+1]=='0')){
        choose_road(list_plane,n,x+1,y,new_map_point);
        new_map_point[y][x+1]=0;
    }
    list_plane[y][x]='*';
    return 0;
}
int main(){
    int i=0,j=0,n=0,c1=0;
    char list_plane[20][20]={0};
    int map_point[20][20]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&c1);
            list_plane[i][j]=((char)c1+48);
        }
    }
    choose_road(list_plane,n,1,1,map_point);
    return 0;
}
