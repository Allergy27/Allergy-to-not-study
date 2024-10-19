n=int(input())
a=list(map(int,input().split()))
b=0
for i in range(len(a)-1):
    if a[i]>1 and a[i+1]>0:
        a[i+1]-=a[i]//2
        b+=a[i]//2
        a[i]-=2*(a[i]//2)
if a[n-1]>1 and a[0]>0:
    a[0]-=a[n-1]//2
    b+=a[n-1]//2
    a[n-1]-=2*(a[n-1]//2)
if sum(a)>2:b+=1
print(b)