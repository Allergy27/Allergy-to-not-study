n=int(input())
for i in range(n):
    a=int(input())
    b=list(map(int,input().split()))
    ans=0
    qaq=0
    for j in range(1,len(b)):
        qwq=0
        if b[j-1]>b[j]:
            while b[j-1] > b[j]*2**qwq:qwq+=1
            qaq+=qwq
        else:
            while b[j] > b[j-1]*2**qwq:qwq+=1
            qwq-=1
            if qaq-qwq>0:qaq-=qwq
            else:qaq=0
        ans+=qaq
    print("                ",ans)