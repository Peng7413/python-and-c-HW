def cal(a1,a2,b1,b2,c1,c2):

    r1=max(a1,a2,b1,b2,c1,c2)
    r2=min(a1,a2,b1,b2,c1,c2)
    r3=r1-r2

    f1=abs(a2-a1)
    f2=abs(b2-b1)
    f4=abs(c2-c1)
    f3=f1+f2+f4

    g1=max(a1,a2,b1,b2)
    g2=min(a1,a2,b1,b2)
    g6=f1+f2
    g4=abs(c2-c1)
    g5=g1-g2
    g3=g5+g4

    h1=max(a1,a2,c1,c2)
    h2=min(a1,a2,c1,c2)
    h6=f1+f4
    h5=h1-h2
    h4=abs(b2-b1)
    h3=h5+h4

    e1=max(c1,c2,b1,b2)
    e2=min(c1,c2,b1,b2)
    e5=e1-e2
    e6=f2+f4
    e4=abs(a2-a1)
    e3=e5+e4

    if(f3>r3):
        return r3
    elif(r3>=f3 and g5>=g6 and h5>=h6 and e5>=e6):
        return f3
    elif(g6>g5):
        return g3
    elif(h6>h5):
        return h3
    elif(e6>e5):
        return e3


def main():
    a1=int(input())
    a2=int(input())
    b1=int(input())
    b2=int(input())
    c1=int(input())
    c2=int(input())
    result=cal(a1,a2,b1,b2,c1,c2)
    print('%d' %result)
	
main()
