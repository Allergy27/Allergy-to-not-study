a=int(input())
b=list(map(int,input().split()))
Min=b[0]
smin=1000000000000000
for i in b[1:]:
    if i<Min:Min=i
    elif i<smin:smin=i
print(round(min((Min+max(b))/2.0,smin/1.0),1))