def cal(list_code,list_in):
    list_s1=[]
    list_result=[]
    list_in.remove('-1')
    list_code2=[]
    for h,l in enumerate(list_code):
        list_code2.append(l)
        
        
    for k in range(len(list_in)):
        r1=0
        r2=0
        c1,c2,c3,c4=map(int,list_in[k].split(' '))
        list_s1.append(c1)
        list_s1.append(c2)
        list_s1.append(c3)
        list_s1.append(c4)
        for i,j in enumerate(list_s1):
            if(list_code2[i]==j):
                r1=r1+1
                list_code2[i]=' '
                list_s1[i]='.'
        for i in range(len(list_code2)):
            for j in range(len(list_s1)):
                if(list_s1[i]==list_code2[j]):
                    r2=r2+1
                    list_code2[j]=' '
                    list_s1[i]='.'
        c5=('{0}A{1}B'.format(r1,r2))
        list_result.append(c5)
        list_s1.clear()
        list_code2.clear()
        for h,l in enumerate(list_code):
            list_code2.append(l)
    return list_result


def main():
    x2_1,x2_2,x2_3,x2_4=map(int,input().split(' '))
    list_code=[]
    list_code.append(x2_1)
    list_code.append(x2_2)
    list_code.append(x2_3)
    list_code.append(x2_4)
    list_in=[]
    while(1):
        x1=input()
        list_in.append(x1)
        if('-1' in list_in):
            break
    result=cal(list_code,list_in)
    for i in range(len(result)):
        print(result[i])

main()
