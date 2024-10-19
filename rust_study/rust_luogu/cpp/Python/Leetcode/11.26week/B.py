YUAN=['a','e','i','o','u']
count=0
s="abbabaab"
k=1
qwqY=[0 for i in range(len(s)+1)]
qwqF=[0 for i in range(len(s)+1)]
for i in range(len(s)):
    qwqY[i+1]=qwqY[i]+1 if (s[i] in YUAN) else qwqY[i]
    qwqF[i+1]=qwqF[i] if (s[i] in YUAN) else qwqF[i]+1
qvq=0
qwqC=[qwqY[i]-qwqF[i] for i in range(len(s)+1)]
for x in range(1,len(s)+1):
     if (qwqY[x]-qwqY[qvq])==(qwqF[x]-qwqF[qvq]) and (qwqF[x]-qwqF[qvq])*(qwqY[x]-qwqY[qvq])%k==0:
        count+=1
        qvq+=1
print(count)