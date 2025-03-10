import sys
import math
from math import gcd
from collections import defaultdict


def main():
    max_n = 2 * 10**5
    spf = list(range(max_n + 1))
    for i in range(2, int(math.sqrt(max_n)) + 1):
        if spf[i] == i:
            for j in range(i * i, max_n + 1, i):
                if spf[j] == j:
                    spf[j] = i

    def factorize(n):
        factors = {}
        while n > 1:
            p = spf[n]
            while n % p == 0:
                factors[p] = factors.get(p, 0) + 1
                n //= p
        return factors

    t = int(sys.stdin.readline())
    for _ in range(t):
        n = int(sys.stdin.readline())
        a = list(map(int, sys.stdin.readline().split()))
        freq = defaultdict(int)
        for num in a:
            freq[num] += 1
        unique = list(freq.keys())
        m = len(unique)
        ans = 0

        factor_cache = {}
        for num in unique:
            factor_cache[num] = factorize(num)

        for i in range(m):
            x = unique[i]
            fx = factor_cache[x]
            for j in range(i, m):
                y = unique[j]
                fy = factor_cache[y]

                merged = {}
                for p, e in fx.items():
                    merged[p] = max(e, merged.get(p, 0))
                for p, e in fy.items():
                    merged[p] = max(e, merged.get(p, 0))

                primes = list(merged.keys())
                valid = False
                if len(primes) == 1:
                    if merged[primes[0]] == 2:
                        valid = True
                elif len(primes) == 2:
                    if merged[primes[0]] == 1 and merged[primes[1]] == 1:
                        valid = True
                else:
                    valid = False

                if valid:
                    if x == y:
                        cnt = freq[x] * (freq[x] + 1) // 2
                    else:
                        cnt = freq[x] * freq[y]
                    ans += cnt
        print(ans)


if __name__ == "__main__":
    main()
