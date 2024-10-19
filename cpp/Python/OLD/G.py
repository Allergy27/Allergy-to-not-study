a=list(map(int,input().split()))
b=list(map(int,input().split()))
t=[0 for i in range(a[1])]
def check(m,n,i):
    if b[i]==1:
        t[(m+n)//2]=1
    if b[i]==2:
        t[(m+n)//2]=1
        t[(m+n)//2+1]=1
    check(m,(m+n)//2,i+1)
    check((m+n)//2+1,n,i+1)

check(0,a[1],0)
print(t)