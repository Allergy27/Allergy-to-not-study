def rck(y):
    for j in range(2,10):
        if str(j) in y:
            return False
    return True

def qvq(x):
    l="1"*(len(str(x))+1)
    for i in range(2,int(l,2)):
        r=int("{0:b}".format(i))
        while x%r==0:
            x/=r
    ck=str(x)
    return rck(ck)

n=int(input())
for _ in range(n):
    t=int(input())
    if rck(str(t)) or qvq(t):print("Yes")
    else: print("No")