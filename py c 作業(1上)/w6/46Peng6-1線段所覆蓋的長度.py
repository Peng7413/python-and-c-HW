list_result=[]
def cal(list_in):
    list_deal=[]
    lcrepeat=0
    lcadd=0
    e1=0
    for k in range(len(list_in)):
        if(list_in[k].find(' ')==-1):
            list_result.append(int(-1))
            e1=1
            break
        c1,c2=map(int,list_in[k].split(' '))
        if(c1<0 or c1>60000 or c2<0 or c2>60000):
            list_result.append(int(-1))
            e1=1
            break
        if(c1>c2):
            list_result.append(int(-1))
            e1=1
            break


        a=[i for i in range(c1,c2+1)]
        list_deal.append(a)
    if(e1==0):
        for k in range(len(list_deal)):
            lc1=list_deal[k][-1]-list_deal[k][0]
            lcadd=lcadd+lc1
            for j in range(len(list_deal)):
                f1=set(list_deal[k]).intersection(set(list_deal[j]))
                if(f1):
                    if(k!=j):
                        f2=list(f1)
                        lc2=f2[-1]-f2[0]
                        lcrepeat=lcrepeat+lc2
        list_result.append(lcadd-(lcrepeat//2))
    return list_result



def main():
    list_in=[]
    result=[]
    e1=0
    thing=int(input())
    for i in range(thing):
        line=int(input())
        list_in.clear()
        for j in range(line):
            if(line>5000):
                result.append(int(-1))
                e1=1
                break
            list_in.append(input())
        if(e1==0):
            result=cal(list_in)
    for i in range(len(result)):
        if(result[i]==-1):
            print('E')
        else:
            print(result[i])

            
main()
