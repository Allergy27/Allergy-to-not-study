n = int(input())
a, b = map(int, input().split())
ans = []
for i in range(n):
    ans.append([int(i) for i in input().split()])
ans.sort(key=lambda x: (x[0] * x[1]))
s = 0
for i in range(n):
    s = max(s, a // ans[i][1])  # 整除， 如果不整除会出错
    a *= ans[i][0]
print(s)
