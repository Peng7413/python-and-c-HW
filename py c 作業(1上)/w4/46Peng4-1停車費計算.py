def cal():
    t1, t1_2= map(int,input().split(':'))
    t2, t2_2= map(int,input().split(':'))
    t3, t3_2= map(int,input().split(':'))
    t4, t4_2= map(int,input().split(':'))
    t5, t5_2= map(int,input().split(':'))
    t6, t6_2= map(int,input().split(':'))
    
    r1=0
    r2=0
    r3=0

    if(t1>=24 or t1_2>=60 or t1<0 or t1_2<0):
        r1=1
    if(t2>=24 or t2_2>=60 or t2<0 or t2_2<0):
        r1=1
    if(t3>=24 or t3_2>=60 or t3<0 or t3_2<0):
        r2=1
    if(t4>=24 or t4_2>=60 or t4<0 or t4_2<0):
        r2=1
    if(t5>=24 or t5_2>=60 or t5<0 or t5_2<0):
        r3=1
    if(t6>=24 or t6_2>=60 or t6<0 or t6_2<0):
        r3=1

    x1=(t2*60+t2_2)-(t1*60+t1_2)
    x2=(t4*60+t4_2)-(t3*60+t3_2)
    x3=(t6*60+t6_2)-(t5*60+t5_2)
    if(x1<0):
        r1=1
    if(x2<0):
        r2=1
    if(x3<0):
        r3=1



    c1=x1//30
    c1_2=x1%30

    c2=x2//30
    c2_2=x2%30

    c3=x3//30
    c3_2=x3%30



    if(c1<4):
        cost1=c1*30
    elif(c1>=4 and c1<8):
        if(c1_2!=0):
            cost1=((c1-4)*40)+160
        else:
            cost1=(c1-4)*40+120
    elif(c1>=8):
        if(c1_2!=0):
            cost1=((c1-8)*60)+340
        else:
            cost1=(c1-8)*60+280

    if(c2<4):
        cost2=c2*30
    elif(c2>=4 and c2<8):
        if(c2_2!=0):
            cost2=((c2-4)*40)+160
        else:
            cost2=(c2-4)*40+120
    elif(c2>=8):
        if(c2_2!=0):
            cost2=((c2-8)*60)+340
        else:
            cost2=(c2-8)*60+280

    if(c3<4):
        cost3=c3*30
    elif(c3>=4 and c3<8):
        if(c3_2!=0):
            cost3=((c3-4)*40)+160
        else:
            cost3=(c3-4)*40+120
    elif(c3>=8):
        if(c3_2!=0):
            cost3=((c3-8)*60)+340
        else:
            cost3=(c3-8)*60+280
	
    return r1,r2,r3,cost1,cost2,cost3


def main():
    che1,che2,che3,result1,result2,result3=cal()
    if(che1==1):
        print('error')
    elif(che1==0):
        print(result1)

    if(che2==1):
        print('error')
    elif(che2==0):
        print(result2)

    if(che3==1):
        print('error')
    elif(che3==0):
        print(result3)

main()
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

