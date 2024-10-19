a=int(input())
b=input()
b=int(b,a)
def qwq(rn,m):
    pq=''
    if m!=16:
        while rn>0:
            pq=str(rn%m)+pq
            rn//=m
        rn=str(rn)
    else:
        pq=hex(rn)[2:]
    return pq

for i in range(1,31):
    b+=int(qwq(b,a)[::-1],a)
    if qwq(b,a)==qwq(b,a)[::-1]:
        print("STEP="+str(i))
        break
else:
    print("Impossible!")