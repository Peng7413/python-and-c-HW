def main():
    a=int(input())
    b=int(input())
    c=int(input())
    d=int(input())
    e=int(input())
    n,k=cal(a,b,c,d,e)
    if(k==1):
        print('%d'%n)
        print('183')
    elif(k==2):
        print('%d'%n)
        print('383')
    elif(k==3):
        print('%d'%n)
        print('983')
        
        
        
        
def cal(a,b,c,d,e):
    x1=a*0.08+b*0.139+c*0.135+d*1.128+e*1.483
    x2=a*0.07+b*0.130+c*0.121+d*1.128+e*1.483
    x3=a*0.06+b*0.108+c*0.101+d*1.128+e*1.483
    if(x1<383):
        if(x1<183):
            x1=183
        return x1,1
    elif(x2<983):
        if(x2<383):
            x2=383
        return x2,2
    elif(x3>983):
        if(x3<983):
            x3=983
        return x3,3

main()