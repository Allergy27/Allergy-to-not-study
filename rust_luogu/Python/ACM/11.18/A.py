a,b=map(int,input().split())
k=[[0],[1],[2],[1,2],[4],[1,4],[2,4],[1,2,4]]
A=k[a]
B=k[b]
C=[]
for i in A:
    for j in B:
        if i not in C:C.append(i)
        if j not in C:C.append(j)
print(sum(C))