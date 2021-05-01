#include <stdio.h>
#include <stdlib.h>
#define GATEVALUE(TYPE) int(*GateValue)(int)
#define GATEVALUE2(TYPE) int(*GateValue2)(int,int)
int GateGetValue(int in1){return in1;}
int GateNotValue(int in1){return !in1;}
int GateAndValue(int in1,int in2){return (in1&&in2);}
int GateOrValue(int in1,int in2){return (in1||in2);}
typedef struct _Gate{
    int in1;
    GATEVALUE();
}Gate;
typedef struct _Gate2{
    int in1;
    int in2;
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
    Gate2 Q_gate,R_gate;
    int x1,x2,x3,y1,y2,y3;
    int i=0;
    char P_gate_d,Q_gate_d,R_gate_d;
    char input[10];
    scanf("%d,%d,%d",&x1,&x2,&x3);
    scanf("%s",input);
    P_gate_d=input[0];
    Q_gate_d=input[2];
    R_gate_d=input[4];
    P_gate.in1=x1;
    if(P_gate_d=='N')
        CreateGateNot(&P_gate);
    else if(P_gate_d=='E')
        CreateGate(&P_gate);
    y1=P_gate.GateValue(P_gate.in1);
    Q_gate.in1=y1;
    Q_gate.in2=x2;
    if(Q_gate_d=='A')
        CreateGateAND(&Q_gate);
    else if(Q_gate_d=='O')
        CreateGateOR(&Q_gate);
    y2=Q_gate.GateValue2(Q_gate.in1,Q_gate.in2);
    R_gate.in1=y2;
    R_gate.in2=x3;
    if(R_gate_d=='A')
        CreateGateAND(&R_gate);
    else if(R_gate_d=='O')
        CreateGateOR(&R_gate);
    y3=R_gate.GateValue2(R_gate.in1,R_gate.in2);
    printf("%d,%d,%d",y1,y2,y3);
    return 0;
}
