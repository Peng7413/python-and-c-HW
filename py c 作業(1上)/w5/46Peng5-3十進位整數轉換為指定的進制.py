
def main():
    n=input()
    f1=0
    c1,c2=n.split(' ')
    if(c1.isdigit() and c2.isdigit()):
        c1=int(c1)
        c2=int(c2)
        if(c2>=0 and c2<=1000000000 and c1>=2 and c1<=16):
            list=[]
            while(c2>=c1):
                c3=c2%c1
                if(c3==10):
                    list.append('A')
                elif(c3==11):
                    list.append('B')
                elif(c3==12):
                    list.append('C')
                elif(c3==13):
                    list.append('D')
                elif(c3==14):
                    list.append('E')
                elif(c3==15):
                    list.append('F')
                elif(c3<10):
                    list.append(c3)
                c2=c2//c1
                c2=int(c2)
            if(c2==10):
                list.append('A')
            elif(c2==11):
                list.append('B')
            elif(c2==12):
                list.append('C')
            elif(c2==13):
                list.append('D')
            elif(c2==14):
                list.append('E')
            elif(c2==15):
                list.append('F')
            elif(c2<10):
                list.append(c2)
        else:
            f1=1
    else:
        f1=1
        
        
    if(f1==1):
        print('E')
    else:
        for i in range(len(list)-1,0,-1):
            print(list[i],end='')
        print(list[0],end='')

main()

















