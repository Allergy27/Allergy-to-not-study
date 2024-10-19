n,s,m=map(int,input().split())
A=n-m
C=2*(n*s-(n+10**7)*A)/10**7
if(C>int(C)):C=int(C)+1
else:C=int(C)
D=m-C
B=int((s-(A+C*0.5)*10**7/n))
if int((2*A+C)*10**7/n+B)>2*s:B-=1
elif int((2*A+C)*10**7/n+B)<2*s:B+=1
print("p"+str(A)+"(+"+str(B)+") f"+str(C)+" l"+str(D))