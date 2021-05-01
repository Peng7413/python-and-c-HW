def cal(a,b,c):
    if(a+b>c and a+c>b and b+c>a and a>0 and b>0 and c>0):
        if(a==b and a==c and b==c and a>0 and b>0 and c>0):
            return 2
        if(a==b or a==c or b==c and a*a+b*b>c*c and c*c+b*b>a*a and a*a+c*c>b*b and a>0 and b>0 and c>0):
            return 3
        if(a+b>c and a+c>b and b+c>a and a>0 and b>0 and c>0):
            return 4
    else:
        return 1



def main():
    a, b, c = map(int,input().split())
    k=int(cal(a,b,c))
    if(k==1):
        print('not triangle')
    elif(k==2):
        print('equilateral triangle')
    elif(k==3):
        print('isosceles triangle')
    elif(k==4):
        print('triangle')
		
main()