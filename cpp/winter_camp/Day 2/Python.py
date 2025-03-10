import sys


def ask(a, b):
    print("?", a, b)
    sys.stdout.flush()
    return int(input())


cas = int(input())
for ca in range(cas):
    l = 2
    r = 999
    while l < r:
        if (r - l + 1) >= 3:
            mid = (r - l + 1) // 3
            x, y = l + mid, r - mid
            a = ask(x, y)
            if a == x * y:
                l = y + 1
            elif a == x * (y + 1):
                l = x + 1
                r = y
            else:
                r = x
        else:
            a = ask(l, r)
            if a == (l) * (r + 1):
                l = r
            else:
                r -= 1
    print("!", l)
    sys.stdout.flush()
