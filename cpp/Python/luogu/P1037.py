a=list(map(str,input().split()))
b={}
c=[]
for i in range(int(a[1])):
    t=list(map(str,input().split()))
    if t[0] not in b:
        b[t[0]]=[]
        c.append(t[0])
    b[t[0]].append(t[1])
def check(tree):
    if tree not in b:#tree是孩子
        return tree
    else:
        te=[]
        for tr in b[tree]:
            te.append(check(tr))
        return te
for i in c:
    b[i]=check(i)
for i in a[0]:
    Sum=c[int(i)]
print(Sum)