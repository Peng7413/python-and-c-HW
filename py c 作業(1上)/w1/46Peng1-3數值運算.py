def count(num1,num2):
    c1=num1+num2
    if(num1>num2):
        c2=num1-num2
    else:
        c2=num2-num1
    c3=num1/num2
    c4=num1*num2
    return c1,c2,c3,c4

def function():
    num1=int(input())
    num2=int(input())
    Su,Differenc,Quotien,Produc=count(num1,num2)
    print("Difference:%.2f" %Differenc)
    print("Sum:%.2f" %Su)
    print("Quotient:%.2f" %Quotien)
    print("Product:%.2f" %Produc)

function()