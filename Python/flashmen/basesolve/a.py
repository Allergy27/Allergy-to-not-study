# Author: Allergy
# Email: Allergy527@gmail.com
# Workspace: flashmen/a.py
# Date: 2024-10-26


def solve():
    a, b, c = map(int, input().split())
    if a < b < c:
        print("STAIR")
    elif a < b > c:
        print("PEAK")
    else:
        print("NONE")


if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        solve()
