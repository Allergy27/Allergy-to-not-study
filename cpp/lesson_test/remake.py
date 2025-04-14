d = [
    [1, 4, 4, 4, 4],
    [3, 2, 3, 3, 3],
    [4, 2, 3, 4, 5],
    [1, 3, 3, 4, 3],
    [4, 3, 3, 3, 5],
]
n = 5


def check(i, j):
    print("{} 到 {} 的最短路径为：{} -> ".format(i + 1, j + 1, i + 1), end="")

    p = d[i][j]  # 指针,指向最短路径
    while p != j + 1:
        print("%d -> " % p, end="")
        p = d[p - 1][j]
    print(j + 1)


for i in range(n):
    for j in range(n):
        check(i, j)
