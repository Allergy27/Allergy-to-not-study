_=int(input())
for __ in range(_):
    x,y,n=map(int,input().split())
    if x+(n*n-n)//2>y:print(-1)
    else:
        a=[]
        for i in range(1,n):
            a.append(y-(i*i-i)//2)
        print(x,end=' ')
        for i in a[::-1]:
            print(i,end=' ')
        print()