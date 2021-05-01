def cal():
    mon=int(input())
    kwh_last=int(input())
    kwh=int(input())

    if(mon>=7 and mon<=9):
        if(kwh<=120):
            cost=kwh*2.10
        elif(kwh>120 and kwh<=330):
            cost=kwh*3.02
        elif(kwh>330 and kwh<=500):
            cost=kwh*4.39
        elif(kwh>500 and kwh<=700):
            cost=kwh*4.97
        elif(kwh>700):
            cost=kwh*5.63
        if(kwh<kwh_last):
            cost=cost-(kwh_last-kwh)*0.6
    else:
        if(kwh<=120):
            cost=kwh*2.10
        elif(kwh>120 and kwh<=330):
            cost=kwh*2.68
        elif(kwh>330 and kwh<=500):
            cost=kwh*3.61
        elif(kwh>500 and kwh<=700):
            cost=kwh*4.01
        elif(kwh>700):
            cost=kwh*4.50
        if(kwh<kwh_last):
            cost=cost-(kwh_last-kwh)*0.6


    return cost


def main():

    result=cal()
    print('%.2f' %result)

main()

















