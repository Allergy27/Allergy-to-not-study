v,w=map(int,input().split())
t=0
while v<=w:
    t+=1
    v*=3
    w*=2
print(t)