a=list(map(int,input().split()))
a.sort()
ans=1
if a[-1]>=118:ans=10
elif a[-4]>=63:ans=8
elif a[-4]>=41:ans=3
print(ans)