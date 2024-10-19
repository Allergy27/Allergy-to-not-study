global n
n=int(input())
ans=[]
for i in range(n):
    ans.append(list(map(str,input().split())))
qwq={}
#寻找对应关系
for i in range(1,n):
    pvp=0
    for j in range(1,n):
        if len(ans[i][j])>1:pvp+=1
    qwq[ans[0][i]]=pvp
def qaq(pp):
    mm=qwq[pp[0]]
    if len(pp)>1:
        mm=qwq[pp[0]]*(n-1)+qwq[pp[1]]
    return mm
flag=0
for i in range(1,n):
    for j in range(1,n):
        if qaq(ans[i][j])==qwq[ans[i][0]]+qwq[ans[0][j]]:
            flag+=1
if flag==(n-1)**2:
    for i in range(n-1):
        print(ans[0][i+1]+"="+str(qwq[ans[0][i+1]]),end=" ")
    print()
    print(n-1)
else:
    print("ERROR!")