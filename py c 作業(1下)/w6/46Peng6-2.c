#include <stdio.h>
void give_value(int *list1,int *list2,int count,int r_or_c){
    int i=0,j=0;
    if(r_or_c==0){
        for(i=0;i<3;i++)
            *(list1+count+i)=*(list2+count+i);
    }
    else if(r_or_c==1){
        for(i=0;i<3;i++)
            *(list1+count+i*3)=*(list2+count+i*3);
    }
}
void give_value2(int *list1,int *list2){
    int i=0;
    for(i=0;i<9;i++)
        *(list1+i)=*(list2+i);
}
void spin2(int *list1,int cw_or_ccw){
    int i=0,j=0;
    int list_re[9]={0};
    if(cw_or_ccw==0){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++)
                list_re[i*3+j]=*(list1+3*(2-j)+i);
        }
    }
    else if(cw_or_ccw==1){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++)
                list_re[i*3+j]=*(list1+3*j+(2-i));
        }
    }
    for(i=0;i<9;i++)
        *(list1+i)=list_re[i];
}
int spin(int *list1[4],int r_or_c,int ccw,char point){
    int i=0,j=0,c1=0,c2=0;
    int store[9]={0};
    for(i=0;i<9;i++){
        store[i]=*(list1[3]+i);
        if(ccw==1)
            store[i]=*(list1[0]+i);
    }
    if(point=='0'){
        c1=0;
        c2=1;
    }
    if(point=='4'){
        c1=3;
        if(r_or_c==1)
            c1=1;
    }
    if(point=='8'){
        c1=6;
        if(r_or_c==1)
            c1=2;
        c2=2;
    }
    for(i=3;i>0;i--){
        if(ccw==1)
            give_value(list1[3-i],list1[3-i+1],c1,r_or_c);
        else
            give_value(list1[i],list1[i-1],c1,r_or_c);
    }
    if(ccw==1)
        give_value(list1[3],store,c1,r_or_c);
    else
        give_value(list1[0],store,c1,r_or_c);
    return c2;
}

void operating_cube(int magic_cube[6][9]){
    int i=0,j=0,c1=0,c2=0,c3=0;
    char order[3]={'\0'};
    int *spin_flat[4];
    int *spin_flat2[2];
    int store1[9];
    scanf("%s",order);
    if(order[0]=='-')
        return;
    if((order[1]=='U')||(order[1]=='D')){
        for(i=0;i<9;i++)
            store1[i]=magic_cube[4][8-i];
        for(i=0;i<9;i++)
           magic_cube[4][i]=store1[i];
        spin_flat[0]=magic_cube[1];
        spin_flat[1]=magic_cube[3];
        spin_flat[2]=magic_cube[4];
        spin_flat[3]=magic_cube[5];
        spin_flat2[0]=magic_cube[0];
        spin_flat2[1]=magic_cube[2];
        if(order[1]=='U')
            c1=1;
        else if(c1==1)
            c3=0;
        c2=spin(spin_flat,1,c1,order[0]);
        if(c2==1)
            spin2(spin_flat2[0],c1);//watch out
        if(c2==2)
            spin2(spin_flat2[1],c3);//watch out
        for(i=0;i<9;i++)
            store1[i]=magic_cube[4][8-i];
        for(i=0;i<9;i++)
           magic_cube[4][i]=store1[i];
    }
    else if(((order[1]=='L')||(order[1]=='R'))&&(order[0]!='C')){
        spin_flat[0]=magic_cube[1];
        spin_flat[1]=magic_cube[2];
        spin_flat[2]=magic_cube[4];
        spin_flat[3]=magic_cube[0];
        spin_flat2[0]=magic_cube[3];
        spin_flat2[1]=magic_cube[5];
        if(order[1]=='L')
            c1=1;
        if(c1==0)
            c3=1;
        else if(c1==1)
            c3=0;
        c2=spin(spin_flat,0,c1,order[0]);
        if(c2==1)
            spin2(spin_flat2[1],c3);//watch out
        if(c2==2)
            spin2(spin_flat2[0],c1);//watch out
    }
    else if((order[0]=='C')&&(order[1]=='R')){
        spin2(magic_cube[1],0);
        for(i=0;i<9;i++)
            store1[i]=magic_cube[0][i];
        magic_cube[0][2]=magic_cube[3][0];
        magic_cube[0][5]=magic_cube[3][1];
        magic_cube[0][8]=magic_cube[3][2];
        magic_cube[3][0]=magic_cube[2][6];
        magic_cube[3][1]=magic_cube[2][3];
        magic_cube[3][2]=magic_cube[2][0];
        magic_cube[2][0]=magic_cube[5][6];
        magic_cube[2][3]=magic_cube[5][7];
        magic_cube[2][6]=magic_cube[5][8];
        magic_cube[5][6]=store1[8];
        magic_cube[5][7]=store1[5];
        magic_cube[5][8]=store1[2];
    }
    else if((order[0]=='C')&&(order[1]=='L')){
            spin2(magic_cube[1],1);
        for(i=0;i<9;i++)
            store1[i]=magic_cube[0][i];
        magic_cube[0][2]=magic_cube[5][8];
        magic_cube[0][5]=magic_cube[5][7];
        magic_cube[0][8]=magic_cube[5][6];
        magic_cube[5][6]=magic_cube[2][0];
        magic_cube[5][7]=magic_cube[2][3];
        magic_cube[5][8]=magic_cube[2][6];
        magic_cube[2][0]=magic_cube[3][2];
        magic_cube[2][3]=magic_cube[3][1];
        magic_cube[2][6]=magic_cube[3][0];
        magic_cube[3][0]=store1[2];
        magic_cube[3][1]=store1[5];
        magic_cube[3][2]=store1[8];
    }
    operating_cube(magic_cube);
}
int main(){
    int i=0,j=0;
    int magic_cube[6][9]={0};
    for(i=0;i<6;i++){
        for(j=0;j<9;j++)
            magic_cube[i][j]=10*(i+1)+j;
    }
    for(i=0;i<9;i++)
        magic_cube[4][i]=50+(8-i);
    operating_cube(magic_cube);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            printf("%d ",magic_cube[1][i*3+j]);
        printf("\n");
    }
    return 0;
}
