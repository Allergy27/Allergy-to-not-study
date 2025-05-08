n, m = map(int, input().split())
a = list(map(str, input().split()))
qwq = [[0, 0, 0] for _ in range(n)]
for i in range(n):

    cnt25, cnt2, cnt5 = 0, 0, 0

    for x in a[i]:
        if x == "2":
            cnt2 += 1
        else:
            cnt5 += 1
            cnt25 += cnt2

    qwq[i] = [cnt25, cnt2, cnt5]


def check(target):
    tmp = 0
    tmp2 = 0
    ans = 0
    time = 0
    for x in qwq:
        new_tmp = tmp + x[0] + tmp2 * x[2]
        if new_tmp > target:
            time += 1
            if time == m:
                return False
            ans = max(ans, tmp)
            tmp = x[0]
            tmp2 = x[1]
        else:
            tmp = new_tmp
            tmp2 += x[1]
            ans = max(ans, tmp)
    ans = max(ans, tmp)
    return ans <= target


l, r = 0, 1e18
while l < r:
    mid = l + r >> 1
    if check(mid):
        r = mid
    else:
        l = mid + 1
print(l)
