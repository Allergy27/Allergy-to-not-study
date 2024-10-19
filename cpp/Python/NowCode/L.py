n=int(input())
m=0
for i in range(n):m+=int(input().count("1")>1)
print(m)