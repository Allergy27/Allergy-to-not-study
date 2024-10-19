input()
a=list(map(int,input().split()))
b=[]
SUM=SSUM=0
for i in a:
    SUM+=i
    b.append(SUM)
for i in range(len(b)-1):
    if b[i]==(b[-1]-b[i]):SSUM+=1
print(SSUM)