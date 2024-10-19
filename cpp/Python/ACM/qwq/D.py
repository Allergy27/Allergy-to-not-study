n=int(input())
a = list(map(int,input().split()))
x,y=max(a),min(a)
ans = (x+y)*(n+1)//2
for i in a:ans-=i
print(ans)