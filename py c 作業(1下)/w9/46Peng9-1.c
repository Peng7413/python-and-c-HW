#include <stdio.h>
typedef struct Shape_s{
    int Circle;
    int Rectangle[2];
    int Square;
    int Triangle[3];
}Shape_t;

int main(){
    Shape_t shape1;
    int n=0,i=0,j=0,PI=4,c1=0,c2=0,total=0;
    char notation,list_input[20]={'\0'};
    int value[3]={0};
    scanf("%d",&n);
    int result[n];
    for(i=0;i<n;i++){
        scanf(" %[^\n]",list_input);
        notation=list_input[0];
        while(list_input[j]!='\0'){
            if(list_input[j]>='0'&&list_input[j]<='9'){
                value[c2]=list_input[j]-'0';
                c2++;
            }
            j++;
        }
        if(notation=='T'){
            c1=0;
            for(j=0;j<3;j++)
                shape1.Triangle[j]=value[j];
            for(j=0;j<3;j++)
                c1+=shape1.Triangle[j];
            result[i]=c1;
            total+=c1;
        }
        else if(notation=='S'){
            shape1.Square=value[0];
            c1=shape1.Square*4;
            result[i]=c1;
            total+=c1;
        }
        else if(notation=='R'){
            for(j=0;j<2;j++)
                shape1.Rectangle[j]=value[j];
            c1=shape1.Rectangle[0]*2+shape1.Rectangle[1]*2;
            result[i]=c1;
            total+=c1;
        }
        else if(notation=='C'){
            shape1.Circle=value[0];
            c1=shape1.Circle*PI*2;
            result[i]=c1;
            total+=c1;
        }
        for(j=0;j<20;j++)
            list_input[j]='\0';
        c2=0;
        j=0;
    }
    for(i=0;i<n;i++)
        printf("%d\n",result[i]);
    printf("%d\n",total);
    return 0;
}
