def f1(list_in):#橫的
    list_locate=[]
    c1=0
    for k in range(0,10,1):
        for i in range(0,6,1):
            list_case=[]
            locate=''
            for j in range(0+i,5+i,1):
                list_case.append(list_in[k][j])
            if(list_case.count(1)==4):
                c1=list_case.index(0)
                locate=str(k)+' '+str(c1+i)
                list_locate.append(locate)
    return list_locate

def f2(list_in):#直的
    list_locate=[]
    c1=0
    for k in range(0,10,1):
        for i in range(0,6,1):
            list_case=[]
            locate=''
            for j in range(0+i,5+i,1):
                list_case.append(list_in[j][k])
            if(list_case.count(1)==4):
                c1=list_case.index(0)
                locate=str(c1+i)+' '+str(k)
                list_locate.append(locate)
    return list_locate

def f3(list_in):#斜的(正斜率)
    list_locate=[]
    c1=0
    for k in range(0,6,1):
        for i in range(4,10,1):
            list_case=[]
            locate=''
            for j in range(0,5,1):
                list_case.append(list_in[k+j][i-j])
            if(list_case.count(1)==4):
                c1=list_case.index(0)
                locate=str(k+c1)+' '+str(i-c1)
                list_locate.append(locate)
    return list_locate

def f4(list_in):#斜的(負斜率)
    list_locate=[]
    c1=0
    for k in range(0,6,1):
        for i in range(0,6,1):
            list_case=[]
            locate=''
            for j in range(0,5,1):
                list_case.append(list_in[k+j][i+j])
            if(list_case.count(1)==4):
                c1=list_case.index(0)
                locate=str(k+c1)+' '+str(i+c1)
                list_locate.append(locate)
    return list_locate

def main():
    list_in=[]
    c1=set()
    c2=set()
    c3=set()
    for i in range(0,10,1):
        data=input().split(' ')
        list_deal=[]
        for j in range(len(data)):
            list_deal.append(int(data[j]))
        list_in.append(list_deal)
    result1=f1(list_in)#list
    result2=f2(list_in)#list
    result3=f3(list_in)#list
    result4=f4(list_in)#list
    c1=set(result1).union(result2)
    c2=set(result3).union(result4)
    c3=set(c1).union(c2)
    c3=list(c3)
    c3.sort()
    for i in range(len(c3)):
        print(c3[i])

main()













