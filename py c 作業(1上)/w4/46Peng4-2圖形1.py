import math

def print01(z):
    for i in range(0,z,1):
        print('*',end='')
    print('')

def print01_2(z):
    for i in range(z,0,-1):
        print('*',end='')
    print('')

def print02(z):
    for i in range(0,z,1):
        print('.',end='')

def print02_2(z):
    for i in range(z,0,-1):
        print('.',end='')



def main():
    ch=int(input())
    if(ch==1):
        f=int(input())
        f2=f/2
        c1=math.ceil(f2)
        c2=math.floor(f2)
        for z in range(1,c1+1,1):
            print01(z)
        for z in range(c2,0,-1):
            print01_2(z)


    elif(ch==2):
        f=int(input())
        f2=f/2
        c1=math.ceil(f2)
        c2=math.floor(f2)
        for z in range(1,c1+1,1):
            print02(c1-z)
            print01_2(z)
        for z in range(c2,0,-1):
            print02(c2-z+1)
            print01_2(z)


    elif(ch==3):
        f=int(input())
        f2=f/2
        c1=math.ceil(f2)
        c2=math.floor(f2)
        for z in range(0,c1,1):
            print02(c1-z-1)
            print01(1+2*z)
        for z in range(0,c2,1):
            print02(z+1)
            print01_2(c2*2-z*2-1)





main()















