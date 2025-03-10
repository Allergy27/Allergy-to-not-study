a = [
    5160,
    9191,
    6410,
    4657,
    7492,
    1531,
    8854,
    1253,
    4520,
    9231,
    1266,
    4801,
    3484,
    4323,
    5070,
    1789,
    2744,
    5959,
    9426,
    4433,
    4404,
    5291,
    2470,
    8533,
    7608,
    2935,
    8922,
    5273,
    8364,
    8819,
    7374,
    8077,
    5336,
    8495,
    5602,
    6553,
    3548,
    5267,
    9150,
    3309,
]
suma = sum(a)
weight = suma // 2
n = len(a)
# 背包,容量是weight
# dp[i][j]表示前i个物品,容量为j时的最大价值
dp = [[0 for _ in range(weight + 1)] for _ in range(n + 1)]

for i in range(n):
    x = a[i]
    for j in range(x, weight + 1):
        if j - x >= 0:
            dp[i + 1][j] = max(dp[i][j - x] + x, dp[i][j])
print((sum(a) - dp[n][weight]) * dp[n][weight])
