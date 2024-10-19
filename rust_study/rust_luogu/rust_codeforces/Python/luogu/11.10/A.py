b,a,R,V,M=map(int,input().split())
for i in (a*R+b*4*R,a*V+b*6*V,a*M+b*6*M):
    print(i,end=" ")