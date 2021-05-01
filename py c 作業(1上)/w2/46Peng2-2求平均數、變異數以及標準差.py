import math


def cal(a,b,c,d,e):
    c1=(a+b+c+d+e)/5
    c2=((a-c1)**2+(b-c1)**2+(c-c1)**2+(d-c1)**2+(e-c1)**2)/5
    c3=math.sqrt(c2)
    return c2, c3, c1





def main():
    a, b, c, d, e= map(int,input().split())
    x1, x2, x3=cal(a,b,c,d,e)
    print('%.2f' %x1)
    print('%.2f' %x2)
    print('%.2f' %x3)

main()