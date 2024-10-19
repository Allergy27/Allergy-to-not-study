N=int(input())
a=list(map(int,input().split()))
b={}
ans=0
for i,num in enumerate(a):
    if num not in b:
        b[num]=[0,i,1]
    else:
        b[num][0]+=(i-b[num][1]-1)*b[num][2]
        ans+=b[num][0]
        b[num][1]=i
        b[num][2]+=1
print(ans)