def cal(num):
    error=0
    list_case=[]
    if(num.isdigit()):
        num=int(num)
        c1=[a for a in range(1,num+1)]
        for j in range(len(c1)):
            c2=0
            list_true=[]
            for i in range(c1[j],c1[-1]):
                c2+=i
                list_true.append(i)
                if(c2==num):
                    list_case.append(list_true)
                    break
    else:
        error=-1
        list_case.append(error)
    return list_case

def main():
    num=input()
    result=cal(num)
    if(result[0]==-1):
        print('E')
    else:
        for i in range(len(result)):
            for j in range(len(result[i])):
                print(result[i][j],end='')
                if(result[i][j]!=result[i][-1]):
                    print('+',end='')
            print()
        print(int(num))
main()