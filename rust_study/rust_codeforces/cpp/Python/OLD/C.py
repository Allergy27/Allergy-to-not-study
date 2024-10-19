n=int(input())
for _ in range(n):
    h,m=map(int,input().split(":"))
    f="AM"
    if h>=12:
        if h>12:h-=12
        f="PM"
    elif h==0:
        h=12
    if h<10:
        print(0,end="")
    print(str(h),end=":")
    if m<10:
        print(0,end="")
    print(str(m)+" "+f)
