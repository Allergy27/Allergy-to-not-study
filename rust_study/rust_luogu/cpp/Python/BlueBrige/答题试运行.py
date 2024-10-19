import os
import sys

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a
T=int(input())
a=list(map(int,input().split()))
k=2
flag=1
tt=a
while flag:
  for i in range(1,len(tt)):
    tt[i-1]=gcd(a[i],a[i-1])
  del tt[-1]
  if tt.count(tt[0])==len(tt):
    print(tt[0])
    flag=0