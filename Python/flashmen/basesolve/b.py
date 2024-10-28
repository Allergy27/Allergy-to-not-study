# Author: Allergy
# Email: Allergy527@gmail.com
# Workspace: flashmen/b.py
# Date: 2024-10-26


def solve():
    n = int(input())
    if n % 2 == 1:
        print("Kosuke")
    else:
        print("Sakurako")


if __name__ == "__main__":
    n = int(input())
    for _ in range(n):
        solve()
