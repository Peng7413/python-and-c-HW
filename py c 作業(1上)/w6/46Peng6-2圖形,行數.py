import math

def printdat(j):
    for i in range(0,j,1):
        print('.',end='')

def printnum(j,f2):
    for i in range(1,f2-j,1):
        print(i,end='')

def printnum2(j,f2):
    for i in range(f2-j,0,-1):
        print(i,end='')
    print('')

def printnum_2(j,c2):
    for i in range(c2*2-1-(2*j),0,-2):
        print(i,end='')

def printnum2_2(j,c2):
    for i in range(3,c2*2+1-(2*j),2):
        print(i,end='')
    print('')


def dia(c2):
    f1=c2/2
    f2=math.ceil(f1)
    f3=math.floor(f1)
    for j in range(f2-1,-1,-1):
        printdat(j)
        printnum(j,f2)
        printnum2(j,f2)
    for j in range(1,f3+1,1):
        printdat(j)
        printnum(j,f2)
        printnum2(j,f2)
    print('')

def tri(c2):
    for j in range(0,c2,1):
        printdat(j)
        printnum_2(j,c2)
        printnum2_2(j,c2)
    print('')

        
def cal(list_in):
    list_in.remove('-1')
    for k in range(len(list_in)):
        c1,c2=map(int,list_in[k].split(' '))
        c2_1=c2%2
        if(c1<1 or c1>2):
            print('E')
            print('')
        elif(c1==1 and (c2<1 or c2>18 or c2_1==0)):
            print('E')
            print('')
        elif(c1==2 and(c2<1 or c2>5)):
            print('E')
            print('')
        else:
            if(c1==1):
                dia(c2)
            elif(c1==2):
                tri(c2)



def main():
    list_in=[]
    while(1):
        x1=input()
        list_in.append(x1)
        if('-1' in list_in):
            break
    cal(list_in)

main()
