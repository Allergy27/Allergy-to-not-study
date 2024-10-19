a=list(map(int,input().split()))
N=a[0]
A=a[1]
B=a[2]
ans=A+B
C=N//ans
D=N%ans
res=0
if D>A:
    res+=A
else:
    res+=D
res+=C*A
print(res)