_=int(input())
for __ in range(_):
    n=int(input())
    a=list(map(int,input().split()))
    b=a[0]
    if max(a)>b or b!=len(a):
        print("NO")
        continue
    c=[[0 for i in range(b)]for j in range(b)]
    for i in range(len(a)):
        c[i]=[1 for k in range(a[i])]+[0 for j in range(a[i],b)]
    d=[[i[j] for i in c]for j in range(b)]
    if c==d:print("YES")
    else:print("NO")
