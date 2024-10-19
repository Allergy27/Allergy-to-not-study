a=list(map(int,input().split()))
b=[input()]
gap=[0 for i in range(a[0]-1)]
Gap=[0 for i in range(a[1])]
ans=[]
def dfs(i,N,n):
    for j in range(N):
        if gap[j]==0:
            Gap[i]=j+1#乘号位置
            gap[j]=1#乘号被占用
            if i==n-1:
                print(Gap)
                qwq=1
                ttk=sorted(Gap+[0,N+1])
                for k in range(1,len(ttk)):qwq*=int(b[0][ttk[k-1]:ttk[k]])
                ans.append(qwq)
            else:dfs(i+1,N,n);#搜索下一个位置
            gap[j]=0;#回溯
        if i==0:j=N-1
dfs(0,a[0]-1,a[1])
print(max(ans))