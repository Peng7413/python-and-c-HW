def translate_and_debug(x1):
    e1=0
    if(x1>=2 and x1<=1000 and type(x1)==int):
        return x1,e1
    elif(x1>1000):
        e1=1
        return x1,e1
    if(x1==0 or x1==1):
        return 1000,e1
    elif(x1<0 and type(x1)==int):
        return x1*-11,e1
    elif(x1>0 and type(x1)==float):
        x2=str(x1).split('.')
        return int(x2[0]),e1
    elif(x1<0 and type(x1)==float):
        x2=str(x1).split('.')
        return int(x2[1]),e1
def find_num(x1):
    for i in range(x1-1,1,-1):
        r1=0
        for j in range(1,i+1,1):
            if(i%j==0):
                r1+=1
        if(r1==2):
            return i
def main():
    x1=input()
    if('.' in x1):
        x1=float(x1)
    else:
        x1=int(x1)
    c1,detect=translate_and_debug(x1)
    if(detect==0):
        c1=find_num(c1)
        print(c1)
    elif(detect==1):
        print('Error!')
main()