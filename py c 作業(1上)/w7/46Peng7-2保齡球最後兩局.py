def transfrom(list_new):
    for i in range(len(list_new)):
        list_new[i]=int(list_new[i])
    return list_new

def strike(list_round,list_nextround,list_nextround2,result):
    if(list_round[0]==10 and list_nextround[0]==10):
        c1=list_round[0]+list_nextround[0]+list_nextround2[0]
        result+=c1
    elif(list_round[0]==10):
        c1=list_round[0]+list_round[1]+list_nextround[0]+list_nextround[1]
        result+=c1
    return result

def spareornot(list_round,list_nextround,result):
    if((list_round[0]+list_round[1])==10 and list_round[0]!=10):
        c1=list_round[0]+list_round[1]+list_nextround[0]
        result+=c1
    elif((list_round[0]+list_round[1])!=10):
        c1=list_round[0]+list_round[1]
        result+=c1
    return result

def cal(list_r9,list_r10,list_bouns,list_nothing):
    result=0
    result=strike(list_r9,list_r10,list_bouns,result)
    result=spareornot(list_r9,list_r10,result)
    result=strike(list_r10,list_bouns,list_nothing,result)
    result=spareornot(list_r10,list_bouns,result)
    return result


def main():
    list_bouns=[0,0]
    list_nothing=[0,0]
    r9=input()
    r10=input()
    list_r9=r9.split(' ')
    list_r10=r10.split(' ')
    list_r9=transfrom(list_r9)
    list_r10=transfrom(list_r10)
    if((list_r10[0]+list_r10[1])==10):
        list_bouns[0]=list_r10[-2]
        list_bouns[1]=list_r10[-1]
        list_r10.remove(list_bouns[0])
        list_r10.remove(list_bouns[1])
    else:
        list_bouns=[0,0]
    score=cal(list_r9,list_r10,list_bouns,list_nothing)
    print(score)
main()