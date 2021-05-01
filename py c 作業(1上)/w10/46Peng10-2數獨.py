def f1(list_in,list_check):
    c1=0
    for i in range(len(list_in)):
        list_case=[]
        for j in range(len(list_in)):
            list_case.append(list_in[i][j])
        list_case.sort()
        if(list_case==list_check):
            c1+=1
    if(c1==9):
        return 1
    else:
        return 0
def f2(list_in,list_check):
    c1=0
    for i in range(len(list_in)):
        list_case=[]
        for j in range(len(list_in)):
            list_case.append(list_in[j][i])
        list_case.sort()
        if(list_case==list_check):
            c1+=1
    if(c1==9):
        return 1
    else:
        return 0
def f3(list_in,list_check):
    c1=0
    for k in range(0,3,1):
        for l in range(0,3,1):
            list_case=[]
            for i in range(0+3*k,3+3*k,1):
                for j in range(0+3*l,3+3*l,1):
                    list_case.append(list_in[i][j])
            list_case.sort()
            if(list_case==list_check):
                c1+=1
    if(c1==9):
        return 1
    else:
        return 0
            
    
def main():
    list_in=[]
    list_check=[1,2,3,4,5,6,7,8,9]
    for i in range(0,9,1):
        data=input().split(' ')
        list_deal=[]
        for j in range(len(data)):
            list_deal.append(int(data[j]))
        list_in.append(list_deal)
    result1=f1(list_in,list_check)
    result2=f2(list_in,list_check)
    result3=f3(list_in,list_check)
    if(result1+result2+result3==3):
        print('Yes')
    else:
        print('No')
main()