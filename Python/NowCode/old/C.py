n,m,a=map(int,input().split())
p=n//a if n%a==0 else n//a+1
q=m//a if m%a==0 else m//a+1
print(p*q)