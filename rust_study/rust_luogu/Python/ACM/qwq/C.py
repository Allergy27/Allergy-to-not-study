n=int(input())
a=list(map(int,input().split()))
for i in range(len(a)-1):
    print(a[i]*a[i+1],end=' ')

