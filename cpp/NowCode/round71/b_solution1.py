def solve():
    n = int(input())
    s = input().strip()
    qwq = [(-1, -1) for i in range(26)]
    ans = n - 1
    for i in range(n):
        tmp = ord(s[i]) - ord("a")
        if qwq[tmp][0] == -1:
            qwq[tmp] = (i, i)
        else:
            ans = min(ans, min(i - qwq[tmp][1] - 1, (qwq[tmp][0] + n - i - 1) % n))
            qwq[tmp] = (qwq[tmp][0], i)
    print(-1 if ans == n - 1 else ans)


if __name__ == "__main__":
    # t = 1
    t = int(input())
    for i in range(t):
        solve()
