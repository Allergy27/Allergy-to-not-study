a=[]
for i in range(0,1000):
    for j in range(i,2019):
        if i+j>2019:break
        for k in range(j,2019):
            if i+j+k>2019:break
            if i<j<k and i+j+k==2019 and ( '2' not in str(i) ) and ( '2' not in str(j) ) and ( '2' not in str(k) ):
                b={i,j,k}
                if b not in a:a.append(b)
print(len(a))