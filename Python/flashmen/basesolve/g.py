def solve():
    a, b, c, d = 0, *map(int, input().split())
    bit, f = 1, 1

    for i in range(62):
        bit_b = 1 if (b & bit) else 0
        bit_c = 1 if (c & bit) else 0
        bit_d = 1 if (d & bit) else 0

        if (bit_b and not bit_c and not bit_d) or (not bit_b and bit_c and bit_d):
            f = 0
            break

        a |= (bit * (1 - bit_d)) if (bit_b and bit_c) else bit * bit_d
        bit <<= 1

    print(a if f else -1)


if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        solve()
