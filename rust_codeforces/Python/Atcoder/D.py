n=int(input())
a=[[]for i in range(n)]
for i in range(n):
    a[i]=[x for x in input()]
SUM=[0]
DULL=[0 for i in range(n)]
HANG=[0 for i in range(n)]
for i in range(n):
    HANG[i]=a[i].count('o')
    for j in range(n):
        if a[j][i]=='o':
            DULL[i]+=1
def dfs(x,y):#x为行
    res=DULL[y]
    if res>0 and HANG[x]>0:SUM[0]+=(res-1)*(HANG[i]-1)
for i in range(n):
    for j in range(n):
        if(a[i][j]=='o'):dfs(i,j)
print(SUM[0])