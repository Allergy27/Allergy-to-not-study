_,n=map(int,input().split())
rar=input()
qwq=[rar[i:i+1]for i in range(len(rar))]
for i in range(n):
  a,b,c=input().split()
  if a=='1':
    qwq[int(b)-1]=c
  else:
    if qwq[int(b)-1:int(c)]==qwq[int(b)-1:int(c)][::-1]:print("Yes")
    else: print("No")