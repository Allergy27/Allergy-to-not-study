t=int(input())
for i in range(t):
    input()
    a=list(map(int,input().split()))
    c=max(a[-1]-min(a),max(a)-a[0])
    for m in range(1,len(a)):
        if a[m-1]-a[m]>c:c=a[m-1]-a[m]
    print(c)