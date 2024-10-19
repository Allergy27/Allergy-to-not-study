edges = [[6,1],[3,4],[0,3],[2,0],[5,2],[5,6]]
values = [25,20,16,2,13,8,19]
Fee=[0]
#判断根和子树哪个和更大即可
tree={}
Tree={}
root=[0]
for i in edges:#传入边的关系
    if i[0] not in Tree:Tree[i[0]]=[]
    if i[1] not in Tree:Tree[i[1]]=[]
    Tree[i[0]].append(i[1])
    Tree[i[1]].append(i[0])
def makeTree(k):
    for i in Tree[k]:
        if i not in root:
            root.append(i)
            if k not in tree:tree[k]=[]
            tree[k].append(i)
            makeTree(i)
makeTree(0)
#孩子和
def Tsum(k):
    t=0
    if k in tree:
        for i in tree[k]:t+=values[i]
    return t
#求最大值
def find(k,flag):#flag用来判断根是不是被挖了
    if k not in tree:#如果是叶子节点
        if not flag:Fee[0]+=values[k]
        return
    if values[k]>Tsum(k) or not flag:Fee[0]+=values[k]#挖根
    else:flag=False
    for i in tree[k]:
        find(i,flag)

find(0,True)
print(Fee[0],sum(values))