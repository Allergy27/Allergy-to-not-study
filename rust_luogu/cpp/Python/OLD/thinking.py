a=input()
b=[]
c=''
for i in a:
    if '0'<=i<='9':
        c+=i
    elif len(c)>0:
        b.append(int(c))
        c=''
if len(c)>0:b.append(int(c))
if len(b)==0:print(0,end='')

else:
    b.sort()
    for i in range(len(b)):
        print(b[i],end='')
        if i<len(b)-1:
            print(',',end='')