def cal(r91,r92,r101,r102,re):
    c1=r91+r92+r101+r102+re
    return c1


def main():
    r91=int(input())
    r92=int(input())
    r101=int(input())
    r102=int(input())
    if(r101==10 and r102==0):
        re=int(input())
    else:
        re=0
    score=cal(r91,r92,r101,r102,re)
    print(score)
    
	
main()
