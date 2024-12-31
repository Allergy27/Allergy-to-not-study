def solve():
    n = int(input())
    s = input().strip()
    s += s
    ans = n - 1
    qwq = [-1] * 26
    for i in range(2 * n):
        tmp = ord(s[i]) - ord("a")
        if qwq[tmp] != -1:
            ans = min(ans, i - qwq[tmp] - 1)
        qwq[tmp] = i
    print(-1 if ans == n - 1 else ans)


if __name__ == "__main__":
    # t = 1
    t = int(input())
    for i in range(t):
        solve()
