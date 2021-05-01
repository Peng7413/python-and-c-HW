def build_Invalid(string_in,list_case,list_result,data,i,list_out):
    if(string_in[i].isspace()):
        if(data!=''):
            list_result.append(data)
            list_case.append(list_out[2])
            data=''
        i+=1
        deal(string_in,list_case,list_result,data,i,list_out)
    else:
        data=data+string_in[i]
        i+=1
        build_Invalid(string_in,list_case,list_result,data,i,list_out)

 
def build_Identifier(string_in,list_case,list_result,data,i,list_out):
    if(string_in[i].isalnum() or string_in[i]=='_'):
        data=data+string_in[i]
        i+=1
        build_Identifier(string_in,list_case,list_result,data,i,list_out)
    elif(string_in[i].isspace()):
        if(data!=''):
            list_result.append(data)
            list_case.append(list_out[1])
            data=''
        i+=1
        deal(string_in,list_case,list_result,data,i,list_out)
    else:
        data=data+string_in[i]
        i+=1
        build_Invalid(string_in,list_case,list_result,data,i,list_out)


def build_Number(string_in,list_case,list_result,data,i,list_out):
    if(string_in[i].isdigit()):
        data=data+string_in[i]
        i+=1
        build_Number(string_in,list_case,list_result,data,i,list_out)
    elif(string_in[i].isspace()):
        if(data!=''):
            list_result.append(data)
            list_case.append(list_out[0])
            data=''
        i+=1
        deal(string_in,list_case,list_result,data,i,list_out)
    else:
        data=data+string_in[i]
        i+=1
        build_Invalid(string_in,list_case,list_result,data,i,list_out)


def main():
    list_result=[]
    list_case=[]
    data=''
    i=0
    list_out=[' - Number',' - Identifier',' - Invalid']
    string_in=input()
    deal(string_in,list_case,list_result,data,i,list_out)



def deal(string_in,list_case,list_result,data,i,list_out):
    if('.'==string_in[i]):
        for j in range(len(list_result)):
            print(list_result[j],end='')
            print(list_case[j],end='')
            print('')
    elif(string_in[i].isdigit()):
        data=data+string_in[i]
        i+=1
        build_Number(string_in,list_case,list_result,data,i,list_out)
    elif(string_in[i].isalpha()):
        data=data+string_in[i]
        i+=1
        build_Identifier(string_in,list_case,list_result,data,i,list_out)
    elif(string_in[i].isspace()):
        i+=1
        deal(string_in,list_case,list_result,data,i,list_out)

main()