n=int(input())
def print01(n):
    for i in range(n,2*n,1):
        print('#',end='')
def print02(n):
    for j in range(n,0,-1):
        print(j,end='')
    print('')
def print03(n):
    for k in range(0,n,1):
        print01(n+k)
        print02(n-k)
print03(n)
