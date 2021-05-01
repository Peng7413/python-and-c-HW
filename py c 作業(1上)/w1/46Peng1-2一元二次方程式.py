import math

def count(a,b,c):
    x1=((-b)+math.sqrt(b*b-4*a*c))/(2*a)
    x2=((-b)-math.sqrt(b*b-4*a*c))/(2*a) 
    return x1, x2

def function():
    a=int(input())
    b=int(input())
    c=int(input())
    beta,afa=count(a,b,c)
    print("%.1f" %beta)
    print("%.1f" %afa)

function()