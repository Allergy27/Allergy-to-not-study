edges =[[7,0],[3,1],[6,2],[4,3],[4,5],[4,6],[4,7]]

values = [2,16,23,17,22,21,8,6]
Fee=[0]
#判断根和子树哪个和更大即可
tree={}
root=[]
for i in edges:#建字典树
    if i[0] not in tree:
        tree[i[0]]=[]
        root.append(i[0])
    tree[i[0]].append(i[1])
#子树和
def Tsum(k):
    t=values[k]
    if k not in tree:return t
    for i in tree[k]:
        t+=Tsum(i)
    return t
Sum={}
for i in range(len(values)):
    if i in tree:
        Sum[i]=Tsum(i)-values[i]
    else:
        Sum[i]=values[i]

#求和
def find(k):
    if k not in tree:return
    flag=0
    for i in tree[k]:
        if i not in tree:
            flag=1
    if values[k]>Sum[k] or flag==0:
        Fee[0]+=values[k]
        for i in tree[k]:
            find(i)
    else:
        Fee[0]+=Sum[k]
ans=0
for i in root:
    flag=0
    for j in root:
        if j==i:continue
        if i in tree[j]:
            flag=1
    if flag==0:
        ans=i
        break
find(ans)
print(Fee[0])