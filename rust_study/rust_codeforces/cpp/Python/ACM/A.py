n=int(input())
for i in range(n):
    input()
    a=list(map(int,input().split()))
    Double=0
    Single=0
    for j in a:
        if j%2==0:Double+=1
        else:Single+=1
    print(min(Single,Double))