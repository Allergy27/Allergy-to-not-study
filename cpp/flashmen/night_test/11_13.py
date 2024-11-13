n, m, x = map(int, input().split())
qwq = []
cost = [0 for i in range(n)]
skill = [0 for i in range(m)]
for i in range(n):
    tmp = list(map(int, input().split()))
    cost[i] = tmp[0]
    qwq.append(tmp[1:])
ans = 1000000000

res = 0


def check(qwq):
    for i in qwq:
        if i < x:
            return False
    return True


def dfs(i):
    global skill, res, ans
    if i == n:
        if check(skill):
            ans = min(ans, res)
        return
    if not (check(skill)):
        res += cost[i]
        skill = [qwq[i][j] + skill[j] for j in range(m)]
        dfs(i + 1)
        skill = [skill[j] - qwq[i][j] for j in range(m)]
        res -= cost[i]
    dfs(i + 1)


dfs(0)
print(ans if ans != 1000000000 else -1)
