def main():
    list_notation=[]
    list_num=[]
    list_in=input().split(' ')
    for i in list_in:
        list_notation.append(i[-1])
    for i in list_in:
        list_num.append(int(i.replace(i[-1],'')))
    list_notation.sort()
    list_num.sort()
    result=deal(list_notation,list_num)
    print(result)

def striaght(list_num):
    c3=0
    x1=0
    if(2 in list_num):
        for i in range(len(list_num)):
            if(list_num[i]<10):
                list_num[i]=list_num[i]+13
        list_num.sort()
    for i in range(4):
        if(list_num[i+1]-1==list_num[i]):
            c3+=1
    return c3

def deal(list_notation,list_num):
    list_cards=[]
    c1=c2=c3=0
    c2=list_notation.count(list_notation[0])#同花色判斷
    for i in range(len(list_num)):
        list_cards.append(list_num.count(list_num[i]))
    c3=striaght(list_num)
    if(list_cards.count(2)==2 and list_cards.count(3)!=3):
        return 1
    elif(list_cards.count(2)==4):
        return 2
    elif(list_cards.count(3)==3 and list_cards.count(2)!=2):
        return 3
    elif(c3==4 and c2!=5):
        return 4
    elif(list_cards.count(2)==2 and list_cards.count(3)==3):
        return 5
    elif(list_cards.count(4)==4):
        return 6
    elif(c3==4 and c2==5):
        return 7
    else:
        return 0
main()