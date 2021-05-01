def cal(c1,c2):
    r1=c1*c2
    c1=abs(c1)
    c2=abs(c2)
    if(c1%c2==0):
        c3=c1//c2
    else:
        c3=c1/c2
        c3=round(c3,2)
    if(r1>0):
        return c1,c2,c3
    elif(r1<0):
        return -c1,c2,-c3

def f1(x1,y1,x2,y2):
    if(x1==x2 and y1!=y2):
        print('x={}'.format(x1))
        print('x={}'.format(x1))
    elif(y1==y2 and x1!=x2):
        print('y={}'.format(y1))
        print('y={}'.format(y1))
    else:
        m1,m1_2,m2=cal(y1-y2,x1-x2)
        if((x2*y1-x1*y2)==0):
            b1=b1_2=b2=0
        else:
            b1,b1_2,b2=cal((x2*y1-x1*y2),x2-x1)
        if(b2>0):
            if(m2==1):
                print('y=x+{0}'.format(b2))
                print('y=x+{0}'.format(b2))
            elif(m2==-1):
                print('y=-x+{0}'.format(b2))
                print('y=-x+{0}'.format(b2))
            else:
                print('y={0}x+{1}'.format(m2,b2))
                if(m1%m1_2!=0):
                    if(b1%b1_2!=0):
                        print('y={0}/{1}x+{2}/{3}'.format(m1,m1_2,b1,b1_2))
                    else:
                        print('y={0}/{1}x+{2}'.format(m1,m1_2,b2))
                else:
                    if(b1%b1_2!=0):
                        print('y={0}/{1}x+{2}/{3}'.format(m2,b1,b1_2))
                    else:
                        print('y={0}x+{1}'.format(m2,b2))
        elif(b2<0):
            if(m2==1):
                print('y=x{0}'.format(b2))
                print('y=x{0}'.format(b2))
            elif(m2==-1):
                print('y=-x{0}'.format(b2))
                print('y=-x{0}'.format(b2))
            else:
                print('y={0}x{1}'.format(m2,b2))
                if(m1%m1_2!=0):
                    if(b1%b1_2!=0):
                        print('y={0}/{1}x{2}/{3}'.format(m1,m1_2,b1,b1_2))
                    else:
                        print('y={0}/{1}x{2}'.format(m1,m1_2,b2))
                else:
                    if(b1%b1_2!=0):
                        print('y={0}/{1}x{2}/{3}'.format(m2,b1,b1_2))
                    else:
                        print('y={0}x{1}'.format(m2,b2))
        elif(b2==0):
            if(m2==1):
                print('y=x')
                print('y=x')
            elif(m2==-1):
                print('y=-x')
                print('y=-x')
            else:
                print('y={0}x'.format(m2))
                if(m1%m1_2!=0):
                    print('y={0}/{1}x'.format(m1,m1_2))
                else:
                    print('y={0}x'.format(m2))

def main():
    e1=0
    list_in=input().split(' ')
    for i in list_in:
        if('.' in i):
            e1=1
            break
    if(e1==0):
        x1=int(list_in[0])
        y1=int(list_in[1])
        x2=int(list_in[2])
        y2=int(list_in[3])
        f1(x1,y1,x2,y2)
    elif(e1==1):
        print('Error!')


main()
