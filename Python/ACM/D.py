n=int(input())
A=[[0 for j in range(101)] for i in range(101)]
for i in range(n):
    a,b,c,d=map(int,input().split())
    for p in range(a,b):
        for q in range(c,d):
            A[p][q]=1
B=0
for i in A:
    B+=i.count(1)
print(B)