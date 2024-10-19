x,y,z=map(int,input().split())
if x*y<0 or abs(x)<abs(y) :print(abs(x))
else:
    if abs(z)>abs(y) and z*y>0:print(-1)
    else:print(abs(z)+abs(x-z))