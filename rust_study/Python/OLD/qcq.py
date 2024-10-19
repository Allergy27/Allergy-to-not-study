def qvq(a1,a2,a3):
    pvp=[]
    for i in (a1,a2,a3):
        for j in str(i):
            if j not in pvp:
                pvp.append(j)
    return len(pvp)>8
for a in range(100,400):
    if qvq(a,a*2,a*3):
        print(a,a*2,a*3)