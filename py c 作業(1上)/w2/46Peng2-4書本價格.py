def cal(a1,a2,b1,b2,c1,c2):
    x1=max(a1,a2,b1,b2,c1,c2)
    x2=min(a1,a2,b1,b2,c1,c2)
    x3=x1-x2
    return x3


def main():
    a1=int(input())
    a2=int(input())
    b1=int(input())
    b2=int(input())
    c1=int(input())
    c2=int(input())
    result=cal(a1,a2,b1,b2,c1,c2)
    print(%d %result)
	
main()
