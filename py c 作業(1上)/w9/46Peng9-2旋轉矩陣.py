def main():
    e1=0 
    list_put=[]
    list_box=[]
    list_rotate=[]
    box_wide,box_length=map(int,input().split(' '))
    for i in range(0,box_wide,1):
        x1=input()
        if(len(x1)!=box_length):
            e1=1
        for j in range(len(x1)):
            if(int(x1[j])==0):
                e1=1
        for j in x1:
            list_put.append(j)
        list_box.append(list_put)
        list_put=[]
    rotate=input()
    for i in rotate:
        if(int(i)<1 or int(i)>3):
            e1=1
        list_rotate.append(int(i))
    if(box_length>10 or box_wide>10 or box_length<1 or box_wide<1):
        e1=1
    if(e1==1):
        print('E')
    elif(e1==0):
        c1=list_rotate.count(1)
        c2=list_rotate.count(2)
        c3=list_rotate.count(3)
        result_rotate=(c1*1+c2*3+c3*2)%4
        if(result_rotate==0):
            for i in range(0,box_wide,1):
                for j in range(0,box_length,1):
                    print(list_box[i][j],end='')
                print('')
        elif(result_rotate==1):
            for i in range(0,box_length,1):
                for j in range(box_wide-1,-1,-1):
                    print(list_box[j][i],end='')
                print('')
        elif(result_rotate==2):
            for i in range(box_wide-1,-1,-1):
                for j in range(box_length-1,-1,-1):
                    print(list_box[i][j],end='')
                print('')
        elif(result_rotate==3):
            for i in range(box_length-1,-1,-1):
                for j in range(box_wide-1,-1,-1):
                    print(list_box[j][i],end='')
                print('')
main()
