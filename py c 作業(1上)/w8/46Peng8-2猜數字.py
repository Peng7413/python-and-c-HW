def judge(guess,case,list_num):
    list_newnum=[]
    c1=0
    c2=0            #c2=幾B(初始化)
    c3=0            #c3=幾A(初始化)
    for i in case:
        if(i.isdigit()):
            c2=int(i)
            c1+=c2
    c3=c1-c2
    for i in range(len(list_num)):
        x1=0
        x2=0
        for j in range(len(guess)):
            if(guess[j]==list_num[i][j]):
                x1+=1
            if(guess[j] in list_num[i] and (guess[j]!=list_num[i][j])):
                x2+=1
        if(x1==c3 and x2==c2):
            list_newnum.append(list_num[i])
    return list_newnum

def create_code():
    list_num=[]
    for i in range(10000):
        list_in=[]
        n1=i%10
        n2=(i%100-n1)//10
        n3=(i%1000-n2-n1)//100
        n4=(i%10000-n3-n2-n1)//1000
        n1=str(n1)
        n2=str(n2)
        n3=str(n3)
        n4=str(n4)
        if(n1!=n2 and n1!=n3 and n1!=n4 and n2!=n3 and n2!=n4 and n3!=n4):
            list_in.append(n4)
            list_in.append(n3)
            list_in.append(n2)
            list_in.append(n1)
            list_num.append(list_in)
    return list_num

def main():
    list_num=create_code()
    while(len(list_num)!=1):
        guess,case=input().split(',')
        list_num=judge(guess,case,list_num)
    for i in range(len(list_num[0])):
        print(list_num[0][i],end='')
    print()

main()
