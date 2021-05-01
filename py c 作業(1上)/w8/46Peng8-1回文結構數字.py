list_result=[]
def main():
    n1,n2=map(int,input().split(' '))
    a=[i for i in range(n1,n2+1)]
    for i in range(len(a)):
        x1=str(a[i])
        result=dal(x1)
    if(result==[]):
        print(0)
    else:
        for i in range(len(result)):
            print(result[i],end='')
            if(i!=(len(result)-1)):
                print(' ',end='')

def dal(n):
    list_1=[]
    list_2=[]
    r1=0
    for i in n[::-1]:
        list_1.append(i)
    for i in n[::1]:
        list_2.append(i)
    for i in range(len(list_1)):
        if(list_1[i]==list_2[i]):
            r1+=1
    if(r1==len(list_1) and len(list_1)!=1):
        list_result.append(n)
    return list_result
main()