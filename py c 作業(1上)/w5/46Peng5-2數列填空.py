
def main():
    x1=input()
    f1=0
    if(x1.isdigit()):
        x1=int(x1)
        if(x1>=1 and x1<=20):
            list=[0]*x1
            for i in range(0,x1):
                list[i]=input()
            for j in range(0,x1):
                g1,g2,g3,g4=map(int,list[j].split(' '))
                if(g2/g1==g3/g2 and g3/g2==g4/g3):
                    c1=g2/g1
                    g5=g4*c1
                    print('%d %d %d %d %d' %(g1,g2,g3,g4,g5))
                elif(g2-g1==g3-g2 and g3-g2==g4-g3):
                    c1=g2-g1
                    g5=g4+c1
                    print('%d %d %d %d %d' %(g1,g2,g3,g4,g5))

        else:
            f1=1
    else:
        f1=1
        
        
    if(f1==1):
        print('E')



main()

















