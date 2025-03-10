def check(x):
    n = str(x)
    for i in n:
        if i not in ["0", "1"]:
            return False
    return True


n = 6
a = []


def initial(x, t):
    if t == n:
        a.append(x)
        return
    initial(x * 10 + 1, t + 1)
    initial(x * 10 + 0, t + 1)
