from functools import cache


@cache
def fibo(x):  # 递归
    if x == 0 or x == 1:
        return x
    else:
        return fibo(x - 1) + fibo(x - 2)


Fibo = [0, 1]


def fibo_rem(x):  # 记忆化
    if x >= len(Fibo):
        tmp = fibo_rem(x - 1) + fibo_rem(x - 2)
        Fibo.append(tmp)
    return Fibo[x]


def fibo_ditv(x):  # 递推
    a = [0, 1]
    for _ in range(x):
        a[0], a[1] = a[1], a[0] + a[1]
    return a[0]


print(fibo_rem(100))
