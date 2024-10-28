# Author: Allergy
# Email: Allergy527@gmail.com
# Workspace: flashmen/c.py
# Date: 2024-10-26


def solve():
    n, m = map(int, input().split())
    s = list(input().strip())
    ans = sum(1 for x in s if x == "B")
    f = 0
    i = 0
    if ans < m:
        f += 2
        while i < n:
            if ans == m:
                break
            if s[i] == "A":
                ans += 1
            i += 1
    elif ans > m:
        f += 1
        while i < n:
            if ans == m:
                break
            if s[i] == "B":
                ans -= 1
            i += 1

    print("1" if f else "0")
    if f != 0:
        print(i, "AB"[f - 1])


if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        solve()
