def count(high,weigh):
    c1=weigh/(high*high)
    return c1

def function():
    high=float(input())
    weigh=float(input())
    BMI1=count(high,weigh)
    print('%.1f'%BMI1)

function()