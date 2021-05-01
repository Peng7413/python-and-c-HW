
def main():
    n=input()
    
    
    if(n.isdigit()):
        n=int(n)
        if(n<0 or n>1000):
            f1=1
        else:
            sum=0
            for j in range(2,n+1):
                c1=1
                for k in range(2,j):
                    if(j%k==0):
                        c1=0
                result=1
                if(c1==1 and n%j==0):
                    for i in range(j,0,-1):
                        result=result*i
                    print('%d,%d' %(j,result))
                    sum=sum+result
                    f1=0
    else:
        f1=1
        
        
    if(f1==1):
        print('E')
    else:
        print(sum)
main()

















