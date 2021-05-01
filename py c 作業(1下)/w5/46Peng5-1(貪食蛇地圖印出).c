#include <stdio.h>
void final_output(int snake[20],int snake_location[20][2],int *re){
    int i=0,r1=0;
    for(i=0;i<11;i++){
        if(snake[i]==0)
        break;
    }
    *re=i;
    for(i=0;i<11;i++){
        if(snake[i]==0)
            break;
        r1=snake_location[i][0]*100+snake_location[i][1];
        *(re+1+i)=r1;
    }
}
int move(int list_map[20][20],int fruit_total[10][2],int snake[20],int snake_location[20][2],int dir[20]){
    int i=0,j=0,k=0,c1=0,c2=0,c3=0,f1=0;
    int new2_snake_location[20][2];
    for(i=0;i<20;i++){
        for(j=0;j<2;j++){
            new2_snake_location[i][j]=snake_location[i][j];
        }
    }
    for(i=0;i<11;i++){
        if(snake[i]!=2)
            break;
    }
    c3=i;
    i=0;
    j=0;
    while(snake[i]==2){
        if(dir[i]==1){
            c1=snake_location[i][0];
            c2=snake_location[i][1];
            list_map[snake_location[i][0]][snake_location[i][1]]=0;
            snake_location[i][0]--;
            list_map[snake_location[i][0]][snake_location[i][1]]=2;
        }
        if(dir[i]==2){
            c1=snake_location[i][0];
            c2=snake_location[i][1];
            list_map[snake_location[i][0]][snake_location[i][1]]=0;
            snake_location[i][0]++;
            list_map[snake_location[i][0]][snake_location[i][1]]=2;
        }
        if(dir[i]==3){
            c1=snake_location[i][0];
            c2=snake_location[i][1];
            list_map[snake_location[i][0]][snake_location[i][1]]=0;
            snake_location[i][1]--;
            list_map[snake_location[i][0]][snake_location[i][1]]=2;
        }
        if(dir[i]==4){
            c1=snake_location[i][0];
            c2=snake_location[i][1];
            list_map[snake_location[i][0]][snake_location[i][1]]=0;
            snake_location[i][1]++;
            list_map[snake_location[i][0]][snake_location[i][1]]=2;
        }
        i++;
    }
    if((snake_location[0][0]==new2_snake_location[c3-1][0])&&(snake_location[0][1]==new2_snake_location[c3-1][1]))
        list_map[snake_location[0][0]][snake_location[0][1]]=2;
    for(j=0;j<10;j++){
        if(list_map[fruit_total[j][0]][fruit_total[j][1]]==2){
            fruit_total[j][0]=-1;
            fruit_total[j][1]=-1;
            for(k=0;k<11;k++){
                if(snake[k]==0){
                    snake[k]=2;
                    snake_location[k][0]=c1;
                    snake_location[k][1]=c2;
                    dir[k]=dir[k-1];
                    list_map[c1][c2]=2;
                    break;
                }
            }
        }
    }
    c1=0;
    c2=0;
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            if(list_map[i][j]==2)
                c1++;
        }
    }
    for(i=0;i<11;i++){
            if(snake[i]==2)
                c2++;
    }
    if(c1!=c2)
        return 1;
    if((snake_location[0][0]==0)||(snake_location[0][0]==19))
        return 1;
    if((snake_location[0][1]==0)||(snake_location[0][1]==19))
        return 1;
    return 0;
}
int game(int list_map[20][20],int fruit_total[10][2],int snake[20],int snake_location[20][2],int dir[20],int *re){
    int i=0,j=0,f1=0,r1=0,input=0,new_map[20][20];
    int new_snake[20],new_snake_location[20][2];
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            new_map[i][j]=list_map[i][j];
        }
    }
    for(i=0;i<20;i++){
        new_snake[i]=snake[i];
        for(j=0;j<2;j++){
            new_snake_location[i][j]=snake_location[i][j];
        }
    }
    scanf("%d",&input);
    if((input>=1)&&(input<=4)){
        if((dir[0]==1)&&(input==2)&&(snake[1]==2)){
            final_output(snake,snake_location,re);
            return 0;
        }
        else if((dir[0]==2)&&(input==1)&&(snake[1]==2)){
            final_output(snake,snake_location,re);
            return 0;
        }
        else if((dir[0]==3)&&(input==4)&&(snake[1]==2)){
            final_output(snake,snake_location,re);
            return 0;
        }
        else if((dir[0]==4)&&(input==3)&&(snake[1]==2)){
            final_output(snake,snake_location,re);
            return 0;
        }
        dir[0]=input;
        game(list_map,fruit_total,snake,snake_location,dir,re);
    }
    else if(input==5){
        f1=move(new_map,fruit_total,new_snake,new_snake_location,dir);
        for(i=10;i>=1;i--){
            if(new_snake[i]!=0)
                dir[i]=dir[i-1];
        }
        for(i=0;i<20;i++){
            for(j=0;j<20;j++){
                printf("%d ",new_map[i][j]);
            }
            printf("\n");
        }
        if(f1==1){
            final_output(snake,snake_location,re);
            return 0;
        }
        game(new_map,fruit_total,new_snake,new_snake_location,dir,re);
    }
    else if(input==0){
        game(list_map,fruit_total,snake,snake_location,dir,re);
        for(i=0;i<11;i++){
            if(snake[i]==0)
            break;
        }
        printf("%d\n",i);
        for(i=0;i<11;i++){
            if(snake[i]==0)
                break;
            for(j=0;j<2;j++){
                printf("%d ",snake_location[i][j]);
            }
            printf("\n");
        }
    }
    else if(input==-1){
        final_output(snake,snake_location,re);
        return 0;
    }
}
int main(){
    int i=0,j=0,n=0,fruit_x=0,fruit_y=0;
    int list_map[20][20]={0};
    int list_result[12]={0};
    int fruit_total[10][2]={-1};
    int snake[20]={0},direct[20]={0};
    int snake_location[20][2]={0};
    snake_location[0][0]=9;
    snake_location[0][1]=9;
    snake[0]=2;
    direct[0]=4;
    list_map[9][9]=snake[0];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&fruit_y,&fruit_x);
        list_map[fruit_y][fruit_x]=1;
        fruit_total[i][0]=fruit_y;
        fruit_total[i][1]=fruit_x;
    }
    game(list_map,fruit_total,snake,snake_location,direct,list_result);
    printf("%d\n",list_result[0]);
    for(i=1;i<12;i++){
        if(list_result[i]!=0)
            printf("%d %d\n",(list_result[i]/100),(list_result[i]%100));
    }
    return 0;
}
