
def add(n1,d1,n2,d2):
    if(n1==0 or d1==0 or n2==0 or d2==0):
        print('ERROR')
    else:
        r1=n1*d2+n2*d1
        c3=0
        c1=d1*d2
        c2=abs(n1*d2+n2*d1)
        x1=simple1(c1,c2)
        c1//=x1
        c2//=x1
        c3,c2=simple2(c1,c2)
        if(c3==0 and c2!=0):
            if(r1<0):
                c2=-c2
            print('{0}/{1}'.format(c2,c1))
        elif(c3!=0 and c2!=0):
            if(r1<0):
                c3=-c3
            print('{0}({1}/{2})'.format(c3,c2,c1))
        elif(c2==0):
            if(r1<0):
                c3=-c3
            print(c3)

def minus(n1,d1,n2,d2):
    if(n1==0 or d1==0 or n2==0 or d2==0):
        print('ERROR')
    else:
        r1=n1*d2-n2*d1
        c3=0
        c1=d1*d2
        c2=abs(n1*d2-n2*d1)
        x1=simple1(c1,c2)
        c1//=x1
        c2//=x1
        c3,c2=simple2(c1,c2)
        if(c3==0 and c2!=0):
            if(r1<0):
                c2=-c2
            print('{0}/{1}'.format(c2,c1))
        elif(c3!=0 and c2!=0):
            if(r1<0):
                c3=-c3
            print('{0}({1}/{2})'.format(c3,c2,c1))
        elif(c2==0):
            if(r1<0):
                c3=-c3
            print(c3)

def multiply(n1,d1,n2,d2):
    if(n1==0 or d1==0 or n2==0 or d2==0):
        print('ERROR')
    else:
        c3=0
        c1=abs(d1*d2)
        c2=abs(n1*n2)
        x1=simple1(c1,c2)
        c1//=x1
        c2//=x1
        c3,c2=simple2(c1,c2)
        if(c3==0 and c2!=0):
            if((n1<0 and n2>0) or (n2<0 and n1>0)):
                c2=-c2
            print('{0}/{1}'.format(c2,c1))
        elif(c3!=0 and c2!=0):
            if((n1<0 and n2>0) or (n2<0 and n1>0)):
                c3=-c3
            print('{0}({1}/{2})'.format(c3,c2,c1))
        elif(c2==0):
            if((n1<0 and n2>0) or (n2<0 and n1>0)):
                c3=-c3
            print(c3)

def divided(n1,d1,n2,d2):
    if(n1==0 or d1==0 or n2==0 or d2==0):
        print('ERROR')
    else:
        c3=0
        c1=abs(d1*n2)
        c2=abs(n1*d2)
        x1=simple1(c1,c2)
        c1//=x1
        c2//=x1
        c3,c2=simple2(c1,c2)
        if(c3==0 and c2!=0):
            if((n1<0 and n2>0) or (n2<0 and n1>0)):
                c2=-c2
            print('{0}/{1}'.format(c2,c1))
        elif(c3!=0 and c2!=0):
             if((n1<0 and n2>0) or (n2<0 and n1>0)):
                c3=-c3
             print('{0}({1}/{2})'.format(c3,c2,c1))
        elif(c2==0):
            if((n1<0 and n2>0) or (n2<0 and n1>0)):
                c3=-c3
            print(c3)


def main():
    i1=input()
    i2=input()
    n1,d1=map(int,i1.split('/'))
    n2,d2=map(int,i2.split('/'))
    add(n1,d1,n2,d2)
    minus(n1,d1,n2,d2)
    multiply(n1,d1,n2,d2)
    divided(n1,d1,n2,d2)

main()
