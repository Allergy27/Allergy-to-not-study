n=int(input())
for i in range(n):
    input()
    a=input()
    b=""
    ans=0
    for i in a[::-1]:
        if i in ['T','A','C','G']:
            if i=='T':b+='A'
            elif i=='A':b+='T'
            elif i=='C':b+='G'
            elif i=='G':b+='C'
        else:
            break
    if len(b)<len(a):print(0)
    else:
        for i in range(len(a)):
            if a[i]==b[i]:ans+=i+1
        print(ans)