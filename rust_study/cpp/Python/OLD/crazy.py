a=[]
for i in range(9):
    a.append(list(map(int,input().split())))
def check(p,q):
    qwq=[]
    for i in range(3):
        for j in range(3):
            if a[p+i][q+j] not in qwq:
                qwq.append(a[p+i][q+j])
    if len(qwq)==9:
        return True
    return False
flag=True
for i in range(9):
    b={}
    c={}
    for j in range(9):
        b[a[i][j]]=1
        c[a[j][i]]=1
        if i%3==0 and j%3==0 and flag:
            flag=check(i,j)
    if not(len(b)==len(c)==9 and flag):
        flag=False
if flag:print("Yes")
else:
    print("No")
