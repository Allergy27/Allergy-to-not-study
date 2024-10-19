n=int(input())
a=int(n**0.5)+1
b=0
ans=abs(n-a**2-b**2)
for i in range(0,int(n**0.5)):
    a-=1 if a>1 else 0
    b=int((n-a**2)**0.5)
    if abs(n-a**2-b**2)<ans:
        ans=abs(n-a**2-b**2)
    if abs(n-a**2-(b+1)**2)<ans:
        ans=abs(n-a**2-(b+1)**2)
if n<=2:print(0)
else:print(ans)