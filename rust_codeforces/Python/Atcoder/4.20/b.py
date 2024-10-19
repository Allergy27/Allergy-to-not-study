a,b=map(int,input().split())
n=list(map(int,input().split()))
m={}
for i in n:
  if i not in m:m[i]=1
  else:del m[i]
print(a-len(m))