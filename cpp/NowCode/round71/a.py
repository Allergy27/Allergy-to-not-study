def solve():
    n, k = map(int, input().split())
    if k > n - 1:
        print("No")
    else:
        print("Yes")


if __name__ == "__main__":
    t = 1
    # t = int(input())
    for i in range(t):
        solve()