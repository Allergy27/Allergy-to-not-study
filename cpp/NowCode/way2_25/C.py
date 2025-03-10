a=""
fibo=[0,1]
for i in range(80):
    a += str(fibo[0]).zfill(20)
    fibo[0],fibo[1] = fibo[1],fibo[0]+fibo[1]
prefix_sum = [0] * (len(a) + 1)
for i in range(1, len(a) + 1):
    prefix_sum[i] = prefix_sum[i - 1] + int(a[i - 1])

def range_sum(l, r):
    return prefix_sum[r + 1] - prefix_sum[l]

n = int(input())
for _ in range(n):
    l, r = map(int, input().split())
    print(range_sum(l, r))