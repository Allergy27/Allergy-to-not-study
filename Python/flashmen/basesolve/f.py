def solve():
    n, m = map(int, input().split())
    qwq = list(map(int, input().split()))
    qwq.sort()
    l, r = 0, 0
    l_ans = r_ans = qwq[0]
    ans = 1

    while r < n:
        r += 1
        if r == n:
            break
        if qwq[r] > r_ans + 1:
            ans = max(ans, r - l)
            l = r
            l_ans = qwq[r]
        r_ans = qwq[r]
        while r_ans - l_ans + 1 > m:
            l += 1
            l_ans = qwq[l]
        ans = max(ans, r - l + 1)

    print(ans)


if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        solve()
