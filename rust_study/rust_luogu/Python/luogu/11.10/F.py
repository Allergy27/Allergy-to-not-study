n,m=map(int,input().split())
a=[]
b=[[0 for i in range(n)] for i in range(m)]
for i in range(2*n):
    a.append(list(map(int,input().split())))
for i in range(0,2*n-1,2):
    for j in range(0,2*m-1,2):
        b[j//2][i//2]=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1]
for i in range(m):
    print(" ".join(list(map(str,b[i]))))