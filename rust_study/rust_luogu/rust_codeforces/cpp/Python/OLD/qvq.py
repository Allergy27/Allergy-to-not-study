def JC(a):
    ans=1
    while(a>1):
        ans*=a
        a-=1
    return ans
q=int(input())
num=0
for i in range(1,q+1):
    num+=JC(i)
print(num)