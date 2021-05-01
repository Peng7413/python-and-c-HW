def count(x,y,z):
    total=x+y+z
    average=(x+y+z)//3
    return average, total

def function():
    n=input()
    s=int(input())
    x=int(input())
    y=int(input())
    z=int(input())
    average1,total1=count(x,y,z)
    print('Name:%s'%n)
    print('ID:%s'%s)
    print('Average:%d' %average1)
    print('Total:%d' %total1)

function()