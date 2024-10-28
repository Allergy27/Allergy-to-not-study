# Author: Allergy
# Email: Allergy527@gmail.com
# Workspace: flashmen/e.py
# Date: 2024-10-26


def solve():
    m, n = map(int, input().split())
    res = (n % 2) * 4 + ((n + 1) // 2) * 7
    if res > m:
        print((n + 1) // 2)
    else:
        print((n + 1) // 2 + (m - res + 14) // 15)


if __name__ == "__main__":
    n = int(input())
    for _ in range(n):
        solve()
