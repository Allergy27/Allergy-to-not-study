from random import randint as rd
a = [rd(-100_000_000, 100_000_000) for _ in range(20)]
a[::2] = sorted(a[::2],reverse=True)
print(a)