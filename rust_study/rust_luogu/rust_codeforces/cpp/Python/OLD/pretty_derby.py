def Count(p,m,n):
    ans=1
    qvq=1
    for i in range(n):
        ans*=m-i
        qvq*=i+1
    k=p**n
    q=(1-p)**(m-n)
    return k*q*(ans/qvq)
print(Count(0.0075*2,400,11))