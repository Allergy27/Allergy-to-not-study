qvq=int(input())
ans=[]
for i in range(qvq):
    qwq=input()
    ans.append(qwq)
rqs=input()
real=[0 for i in range(qvq)]
Maxlen=[0]
def Capable(a,b):#a->大的.b->小的
    for i in range(min(len(a),len(b))-1):
        if a[len(a)-i-1:]==b[:i+1]:return a+b[i+1:]
    return a+b
def dfs(i,N,n):#n：当前字符串
    for j in range(N):
        if real[j]<2 and (Capable(n,ans[j])!=n+ans[j]):#如果能用并且还能装
            real[j]+=1#使用该字符串
            pp=len(n)
            n=Capable(n,ans[j])
            flag=1
            for p in range(N):
                if real[p]<2:
                    if Capable(n,ans[p])!=n+ans[p]:
                        flag=0
                        break
            if flag==1:
                if len(n)>Maxlen[0]:Maxlen[0]=len(n)
            else:dfs(i+1,N,n);#搜索下一个位置
            real[j]-=1;#回溯
            n=n[:pp]
for i in range(len(ans)):
    if ans[i][0]==rqs:
        real[i]+=1
        dfs(0,len(ans),ans[i])
        real[i]-=1
print(Maxlen[0])