n=3
edges=[[0,1],[1,2]]
p={}
q=[]
def Jojo(a):
    
    for i in a:
        t=[]
        for j in p[i]:
            if j in p:
                t.append(Jojo(p[i]))
for i in edges:
    if i[1] not in p:
        p[i[1]]=[]
        q.append(i[1])
    p[i[1]].append(i[0])
Jojo(q)
input()