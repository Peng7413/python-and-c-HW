def main():
    e1=0
    list_P1=input().split(' ')
    list_P2=input().split(' ')
    list_P3=input().split(' ')
    list_P4=input().split(' ')
    king,e1,first_hand,team_goal=callcard()
    team_master_result=first_hand%4
    if(team_goal>3):
        e1=1
    if(team_master_result==1 or team_master_result==3):
        team_master=2
    elif(team_master_result==0 or team_master_result==2):
        team_master=1
    first_hand=(first_hand+1)%4
    e1,result=play(list_P1,list_P2,list_P3,list_P4,first_hand,king,e1)
    if(e1==1):
        print('ERROR')
    else:
        t1_score=result[0]+result[2]
        t2_score=result[1]+result[3]
        for i in range(len(result)):
            print(result[i])
        if(team_master==1):
            if(t1_score<team_goal):
                print('P2 P4')
            else:
                print('P1 P3')
        elif(team_master==2):
            if(t2_score<team_goal):
                print('P1 P3')
            else:
                print('P2 P4')


def dealcall(call_in,king_now):
    list_notation=['D','C','B','A']
    if(int(king_now[0])<int(call_in[0])):
        return True,0
    elif(int(king_now[0])>int(call_in[0])):
        return False,1
    c1=list_notation.index(king_now[1])
    c2=list_notation.index(call_in[1])
    if(c1<c2):
        return True,0
    elif(c1>=c2):
        return False,1

def callcard():
    c1=0
    e1=0
    c2=0
    first_call=0
    while(c1!=3):
        call_in=input()
        if(first_call==0):
            king_now=call_in
            c2+=1
            first_call=1
        elif(call_in[0]!='p' and first_call==1):
            result,e1=dealcall(call_in,king_now)
            if(result):
                king_now=call_in
                c1=0
                c2+=1
        elif(call_in[0]=='p'):
            c1+=1
            c2+=1
    return king_now[-1],e1,c2,int(king_now[0])

def play(list_P1,list_P2,list_P3,list_P4,hand,king,e1):
    list_score=[0,0,0,0]#P1 P2 P3 P4
    for i in range(3):
        c1=0
        list_queue=[]
        compare=[]
        compare_king=[]
        turn_case=input().split(' ')
        for j in range(4):
            if(hand==0):
                if(not(turn_case[j] in list_P1)):
                    e1=1
                    hand+=1
                else:
                    if(j==0):
                        nowturn_notation=turn_case[j][-1]
                        list_P1.remove(turn_case[j])
                        list_queue.append(hand)
                        hand+=1
                    else:
                        list_P1.remove(turn_case[j])
                        list_queue.append(hand)
                        hand+=1
                        if(not(nowturn_notation in turn_case[j])):
                            for k in range(len(list_P1)):
                                if(nowturn_notation in list_P1[k]):
                                    e1=1

            elif(hand==1):
                if(not(turn_case[j] in list_P2)):
                    e1=1
                    hand+=1
                else:
                    if(j==0):
                        nowturn_notation=turn_case[j][-1]
                        list_P2.remove(turn_case[j])
                        list_queue.append(hand)
                        hand+=1
                    else:
                        list_P2.remove(turn_case[j])
                        list_queue.append(hand)
                        hand+=1
                        if(not(nowturn_notation in turn_case[j])):
                            for k in range(len(list_P2)):
                                if(nowturn_notation in list_P2[k]):
                                    e1=1
            elif(hand==2):
                if(not(turn_case[j] in list_P3)):
                    e1=1
                    hand+=1
                else:
                    if(j==0):
                        nowturn_notation=turn_case[j][-1]
                        list_P3.remove(turn_case[j])
                        list_queue.append(hand)
                        hand+=1
                    else:
                        list_P3.remove(turn_case[j])
                        list_queue.append(hand)
                        hand+=1
                        if(not(nowturn_notation in turn_case[j])):
                            for k in range(len(list_P3)):
                                if(nowturn_notation in list_P3[k]):
                                    e1=1
            elif(hand==3):
                if(not(turn_case[j] in list_P4)):
                    e1=1
                    hand=0
                else:
                    if(j==0):
                        nowturn_notation=turn_case[j][-1]
                        list_P4.remove(turn_case[j])
                        list_queue.append(hand)
                        hand=0
                    else:
                        list_P4.remove(turn_case[j])
                        list_queue.append(hand)
                        hand=0
                        if(not(nowturn_notation in turn_case[j])):
                            for k in range(len(list_P4)):
                                if(nowturn_notation in list_P4[k]):
                                    e1=1
        if(e1==0):
            for j in range(4):
                if(king in turn_case[j]):
                    c1+=1
            if(c1==0):
                for j in range(4):
                    if(nowturn_notation in turn_case[j]):
                        if(int(turn_case[j].replace(turn_case[j][-1],''))==1):
                            turn_case[j]='14'+nowturn_notation
                        compare.append(int(turn_case[j].replace(turn_case[j][-1],'')))
                for j in range(4):
                    turn_case[j]=int(turn_case[j].replace(turn_case[j][-1],''))
                hand=list_queue[turn_case.index(max(compare))]
                list_score[hand]+=1
            else:
                for j in range(4):
                    if(king in turn_case[j]):
                        if(int(turn_case[j].replace(turn_case[j][-1],''))==1):
                            turn_case[j]='14'+nowturn_notation
                        compare_king.append(int(turn_case[j].replace(turn_case[j][-1],'')))
                for j in range(4):
                    turn_case[j]=int(turn_case[j].replace(turn_case[j][-1],''))
                hand=list_queue[turn_case.index(max(compare_king))]
                list_score[hand]+=1
    return e1,list_score
main()










