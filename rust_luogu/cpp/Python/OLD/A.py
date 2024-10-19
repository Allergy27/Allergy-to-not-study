qvq=list(map(str,input().split()))
flag='Easy'
qvq[0],qvq[1]=qvq[0][::-1],qvq[1][::-1]
for i in range(min(len(qvq[0]),len(qvq[1]))):
    if int(qvq[0][i])+int(qvq[1][i]) >9:
        flag='Hard'
print(flag)
#
n=int(input())
for _ in range(n):
    qvq=list(map(int,input().split()))
    ans=qvq[1]*60+qvq[2]
    b=[]
    for i in range(qvq[0]):
        c=list(map(int,input().split()))
        b.append(c[0]*60+c[1])
    b.sort()
    b.append(b[0]+1440)
    for i in b:
        if i-ans>=0:
            print((i-ans)//60,(i-ans)%60)
            break
#
n=int(input())
for _ in range(n):
    b=int(input())
    qwq=list(map(int,input().split()))
    qwq.sort()
    print(max(qwq[0]*qwq[1],qwq[-1]*qwq[-2]))
#
n=int(input())
for _ in range(n):
    b=int(input())
    qwq=list(map(int,input().split()))
    c=[]
    ans=1
    for i in range(len(qwq)):
        while ans==qwq[i]:ans+=1
        c.append(ans)
        ans+=1
    print(ans-1)
#
input()
qwq=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))
d={}
e={}
f=[]
for i in c:
    if i not in d:
        d[i]=0
        f.append(i)
    d[i]+=1
for i in f:
    if b[i-1] not in e: e[b[i-1]]=0
    e[b[i-1]]+=d[i]
ans=0
for i in qwq:
    if i in e:ans+=e[i]
print(ans)