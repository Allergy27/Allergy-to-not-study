_=int(input())
for __ in range(_):
    n=int(input())
    a=list(map(int,input().split()))
    Upos=0
    for i in a:
        if i<=0:Upos=(Upos+1)%2
    b=[abs(i) for i in a]
    if Upos:
        print(sum(b)-2*min(b))
    else:
        print(sum(b))
    