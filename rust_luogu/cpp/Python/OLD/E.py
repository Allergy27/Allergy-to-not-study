a=list("5 6 8 6 9 1 6 1 2 4 9 1 9 8 2 3 6 4 7 7 5 9 5 0 3 8 7 5 8 1 5 8 6 1 8 3 0 3 7 9 2 7 0 5 8 8 5 7 0 9 9 1 9 4 4 6 8 6 3 3 8 5 1 6 3 4 6 7 0 7 8 2 7 6 8 9 5 6 5 6 1 4 0 1 0 0 9 4 8 0 9 1 2 8 5 0 2 5 3 3".split())
dy=[31,28,31,30,31,30,31,31,30,31,30,31]
ans={}
for i1 in range(len(a)-7):
    if a[i1]=="2":
        for i2 in range(i1+1,len(a)-6):
            if a[i2]=="0":
                for i3 in range(i2+1,len(a)-5):
                    if a[i3]=="2":
                        for i4 in range(i3+1,len(a)-4):
                            if a[i4]=="3":
                                for i5 in range(i4+1,len(a)-3):
                                    for i6 in range(i5+1,len(a)-2):
                                        m=int(a[i5]+a[i6])
                                        if 1<=m<=12:
                                            for i7 in range(i6+1,len(a)-1):
                                                for i8 in range(i7+1,len(a)):
                                                    if 1<=int(a[i7]+a[i8])<=dy[m-1]:
                                                        ans[str(m)+str(a[i7]+a[i8])]=1

print(len(ans))