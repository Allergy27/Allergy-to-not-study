a=list(map(int,input().split()))
a[0]=(a[0]+1)//2
if a[1]>a[0]:
    print((a[1]-a[0])*2)
else:
    print(a[1]*2-1)