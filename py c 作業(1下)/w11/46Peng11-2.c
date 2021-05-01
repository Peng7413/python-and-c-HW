#include <stdio.h>
#include <stdlib.h>
#define GATEVALUE(TYPE) int(*GateValue)(int)
#define GATEVALUE2(TYPE) int(*GateValue2)(int,int)
int GateGetValue(int in1){return in1;}
int GateNotValue(int in1){return !in1;}
int GateAndValue(int in1,int in2){return (in1&&in2);}
int GateOrValue(int in1,int in2){return (in1||in2);}
typedef struct _Gate{
    GATEVALUE();
}Gate;
typedef struct _Gate2{
    GATEVALUE2();
}Gate2;
void CreateGate(Gate *obj){
obj->GateValue = GateGetValue;
}
void CreateGateNot(Gate *obj){
obj->GateValue = GateNotValue;
}
void CreateGateAND(Gate2 *obj){
obj->GateValue2 = GateAndValue;
}
void CreateGateOR(Gate2 *obj){
obj->GateValue2 = GateOrValue;
}
int main(int argc, char *argv[]){
    Gate P_gate;
    Gate2 Q_gate,R_gate,S_gate,T_gate;
    int x_in[4]={0},y_out[4]={0},tmp=0;
    int i=0;
    char P_gate_d,Q_gate_d,R_gate_d,S_gate_d,T_gate_d;
    char input[10];
    scanf("%d,%d,%d,%d",&x_in[0],&x_in[1],&x_in[2],&x_in[3]);
    scanf("%s",input);
    P_gate_d=input[0];
    Q_gate_d=input[2];
    R_gate_d=input[4];
    S_gate_d=input[6];
    T_gate_d=input[8];
    if(P_gate_d=='N')
        CreateGateNot(&P_gate);
    else if(P_gate_d=='E')
        CreateGate(&P_gate);
    y_out[0]=P_gate.GateValue(x_in[0]);
    if(Q_gate_d=='A')
        CreateGateAND(&Q_gate);
    else if(Q_gate_d=='O')
        CreateGateOR(&Q_gate);
    y_out[1]=Q_gate.GateValue2(y_out[0],x_in[1]);
    if(R_gate_d=='A')
        CreateGateAND(&R_gate);
    else if(R_gate_d=='O')
        CreateGateOR(&R_gate);
    y_out[2]=R_gate.GateValue2(y_out[1],x_in[2]);
    if(S_gate_d=='A')
        CreateGateAND(&S_gate);
    else if(S_gate_d=='O')
        CreateGateOR(&S_gate);
    tmp=S_gate.GateValue2(x_in[3],x_in[2]);
    if(T_gate_d=='A')
        CreateGateAND(&T_gate);
    else if(T_gate_d=='O')
        CreateGateOR(&T_gate);
    y_out[3]=T_gate.GateValue2(y_out[2],tmp);
    for(i=0;i<4;i++){
        printf("%d",y_out[i]);
        if(i<3)
            printf(",");
    }
    return 0;
}
