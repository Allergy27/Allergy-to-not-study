n, m = map(int, input().split())
k = {}
for i in range(m):
    a, b = map(int, input().split())
    if a in k:
        k[a].append(b)
    else:
        k[a] = [b]
aa = list(k.keys())
# print(k)
summ = 0


def dfs(x, visited):  # x表示现在在哪里，visited表示已经走过的地方
    global summ
    if x in k:
        # print(x,k[x])
        for j in k[x]:
            if j not in visited:
                visited.add(j)
                # print(visited)
                summ += 1
                dfs(j, visited)
                visited.remove(j)


for i in range(len(aa)):
    visited = set()
    visited.add(aa[i])
    dfs(aa[i], visited)
    # print(visited)
print(summ + n)
