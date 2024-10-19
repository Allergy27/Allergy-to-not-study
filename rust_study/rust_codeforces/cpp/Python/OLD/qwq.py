a=input()
b=input()
c={'a':1,'b':2,'c':3,'d':4,'e':5,'f':6,'g':7,'h':8}
pos1=[c[a[0]],int(a[1])]
pos2=[c[b[0]],int(b[1])]
x=pos1[0]-pos2[0]
y=pos1[1]-pos2[1]
fang=int(x>0)+int(x*y>0)*2
Pos=["RD","LU","RU","LD"]
print(abs(x)+abs(y)-min(abs(x),abs(y)))
for i in range(min(abs(x),abs(y))):
    print(Pos[fang])
res=max(abs(x),abs(y))-min(abs(x),abs(y))
Fang=int(abs(x)>min(abs(x),abs(y)))*x+int(abs(y)>min(abs(x),abs(y)))*y
if Fang==x:
    for i in range(res):print(Pos[fang][0])
elif Fang==y:
    if x==0:
        for i in range(res):print(Pos[int(y<0)][1])
    else:
        for i in range(res):print(Pos[fang][1])