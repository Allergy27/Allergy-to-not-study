n=int(input())
j=0
while (j**2+j)//2 < n:j+=1
n-=(j**2-j)//2
if j%2==0: print(str(n)+"/"+str(j+1-n))
else:print(str(j+1-n)+"/"+str(n))