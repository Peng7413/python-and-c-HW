def count(num1):
    num2=num1%2
    return num2

def function():
    num1=int(input())
    num3=count(num1)
    if(num3==0):
        print("even")
    else:
        print("odd")

function()