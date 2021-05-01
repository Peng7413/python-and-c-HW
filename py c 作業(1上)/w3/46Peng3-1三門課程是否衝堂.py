
def main():
    class_num1=int(input())
    class_hour1=int(input())
    class_day1=int(input())
    if(class_hour1==2):
        class_day1_2=int(input())

    class_num2=int(input())
    class_hour2=int(input())
    class_day2=int(input())
    if(class_hour2==2):
        class_day2_2=int(input())

    class_num3=int(input())
    class_hour3=int(input())
    class_day3=int(input())
    if(class_hour3==2):
        class_day3_2=int(input())
    g2=10
    g1=16

    if(class_num1<1000 or class_num1>9999):
        g1=g1-1
    if(class_num2<1000 or class_num2>9999):
        g1=g1-1
    if(class_num2<1000 or class_num2>9999):
        g1=g1-1

    if(class_hour1<1 or class_hour1>2):
        g1=g1-1
    if(class_hour2<1 or class_hour2>2):
        g1=g1-1
    if(class_hour3<1 or class_hour3>2):
        g1=g1-1

    if(class_day1<11 or class_day1>=60 or class_day1==20 or class_day1==30 or class_day1==40 or class_day1==50):
        g1=g1-1
    if(class_day2<11 or class_day2>=60 or class_day2==20 or class_day2==30 or class_day2==40 or class_day2==50):
        g1=g1-1
    if(class_day3<11 or class_day3>=60 or class_day3==20 or class_day3==30 or class_day3==40 or class_day3==50):
        g1=g1-1
    if(class_hour1==2):
        if(class_day1_2<11 or class_day1_2>=60 or class_day1_2==20 or class_day1_2==30 or class_day1_2==40 or class_day1_2==50):
            g1=g1-1
    if(class_hour2==2):
        if(class_day2_2<11 or class_day2_2>=60 or class_day2_2==20 or class_day2_2==30 or class_day2_2==40 or class_day2_2==50):
            g1=g1-1
    if(class_hour3==2):
        if(class_day3_2<11 or class_day3_2>=60 or class_day3_2==20 or class_day3_2==30 or class_day3_2==40 or class_day3_2==50):
            g1=g1-1

    if(class_hour1==2):
        if(class_day1==class_day1_2):
            g1=g1-1
    if(class_hour2==2):
        if(class_day2==class_day2_2):
            g1=g1-1
    if(class_hour3==2):
        if(class_day3==class_day3_2):
            g1=g1-1


    if(class_day1==class_day2):
        print('{:d},{:d},{:d}'.format (class_num1,class_num2,class_day1))
        g2=g2-1
    if(class_day1==class_day3):
        print('{:d},{:d},{:d}'.format (class_num1,class_num3,class_day1))
        g2=g2-1
    if(class_hour1==2):
        if(class_day1_2==class_day2):
            print('{:d},{:d},{:d}'.format (class_num1,class_num2,class_day1_2))
            g2=g2-1
        if(class_day1_2==class_day3):
            print('{:d},{:d},{:d}'.format (class_num1,class_num3,class_day1_2))
            g2=g2-1
    if(class_hour1==2 and class_hour2==2):
        if(class_day1_2==class_day2_2):
            print('{:d},{:d},{:d}'.format (class_num1,class_num2,class_day1_2))
            g2=g2-1
    if(class_hour1==2 and class_hour3==2):
        if(class_day1_2==class_day3_2):
            print('{:d},{:d},{:d}'.format (class_num1,class_num3,class_day1_2))
            g2=g2-1
    if(class_hour2==2):
        if(class_day2_2==class_day1):
            print('{:d},{:d},{:d}'.format (class_num1,class_num2,class_day2_2))
            g2=g2-1
    if(class_hour3==2):
        if(class_day3_2==class_day1):
            print('{:d},{:d},{:d}'.format (class_num1,class_num3,class_day3_2))
            g2=g2-1
    if(class_day2==class_day3):
        print('{:d},{:d},{:d}'.format (class_num2,class_num3,class_day2))
        g2=g2-1
    if(class_hour3==2 and class_hour2==2):
        if(class_day3_2==class_day2_2):
            print('{:d},{:d},{:d}'.format (class_num2,class_num3,class_day2_2))
            g2=g2-1
    if(class_hour2==2):
        if(class_day2_2==class_day3):
            print('{:d},{:d},{:d}'.format (class_num2,class_num3,class_day2_2))
            g2=g2-1
    if(class_hour3==2):
        if(class_day3_2==class_day2):
            print('{:d},{:d},{:d}'.format (class_num2,class_num3,class_day3_2))
            g2=g2-1





    if(g1!=16):
        print('-1')

    elif(g2==10):
        print('correct')

main()
























