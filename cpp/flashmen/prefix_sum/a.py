def solve():
    n, m = map(int, input().split())
    qwq = list(map(int, input().split()))
    qaq = [0] * (n + 1)  # 前缀和
    for i in range(1, n + 1):
        qaq[i] = qaq[i - 1] + qwq[i - 1]
    tmp = 0  # 记录每一段长度
    for i in range(m):
        tmp += qwq[i] * (i + 1)
    ans = tmp
    for i in range(m, n):
        tmp -= qaq[i + 1] - qaq[i - m] - qwq[i] * (m + 1)
        ans = max(ans, tmp)  # 更新最大值
    print(ans)
solve()