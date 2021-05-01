void printstar(int n){
int i=0;
for(i=0;i<n;i++){
    printf("*");
}
}
void printdot(int n){
int i=0;
for(i=0;i<n;i++){
    printf(".");
}
}
void f1(int n){
int i=0,c1=0,c2=0;
c1=(n+1)/2;
c2=(n+1)/2-1;
for(i=1;i<=c1;i++){
    printstar(i);
    printf("\n");
}
for(i=1;i<=c2;i++){
    printstar(c2-i+1);
    printf("\n");
}
}
void f2(int n){
int i=0,c1=0,c2=0;
c1=(n+1)/2;
c2=(n+1)/2-1;
for(i=1;i<=c1;i++){
    printdot(c1-i);
    printstar(i);
    printf("\n");
}
for(i=1;i<=c2;i++){
    printdot(i);
    printstar(c2-i+1);
    printf("\n");
}
}
void f3(int n){
int i=0,c1=0,c2=0;
c1=(n+1)/2;
c2=(n+1)/2-1;
for(i=1;i<=c1;i++){
    printdot(c1-i);
    printstar(1+2*(i-1));
    printf("\n");
}
for(i=1;i<=c2;i++){
    printdot(i);
    printstar(1+2*(c2-i));
    printf("\n");
}
}
int main(){
int i=0,input_case=0,input_line=0;
    scanf("%d",&input_case);
    scanf("%d",&input_line);
    if(input_case==1){
        f1(input_line);
    }
    if(input_case==2){
        f2(input_line);
    }
    if(input_case==3){
        f3(input_line);
    }

return 0;
}
