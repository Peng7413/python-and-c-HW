
import math
def cal(a,b,c):
    if((b*b)-(4*a*c)>=0):
        c1=math.sqrt((b*b)-(4*a*c))
        c2=(-b+c1)/(2*a)
        c3=(-b-c1)/(2*a)
        return c2,c3,1
    elif((b*b)-(4*a*c)<0):
        c1=math.sqrt(abs((b*b)-(4*a*c)))/(2*a)
        c2=(-b)/(2*a)
        return c2,c1,2

		
		
def main():
    a=int(input())
    b=int(input())
    c=int(input())
    x1, x2, x3= cal(a,b,c)
    if(x3==1):
        print("%.1f" %x1)
        print("%.1f" %x2)
    elif(x3==2):
        print("%.1f+%.1fi" %(x1, x2))
        print("%.1f-%.1fi" %(x1, x2)) 

main()