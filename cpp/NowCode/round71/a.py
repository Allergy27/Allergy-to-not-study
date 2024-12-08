import sys


def main():
    from itertools import permutations


    sys.setrecursionlimit(1 << 25)
    import sys

    n_and_rest = sys.stdin.read().split()
    n = int(n_and_rest[0])
    colors = n_and_rest[1]
    t = list(map(int, n_and_rest[2 : 2 + n]))

    # Precompute prefix sums for each color
    sum_c = {}
    for c in ["0", "1", "2"]:
        sum_c[c] = [0] * (n + 1)
        for i in range(n):
            sum_c[c][i + 1] = sum_c[c][i] + (0 if colors[i] == c else t[i])

    min_total = float("inf")

    for perm in permutations(["0", "1", "2"]):
        c1, c2, c3 = perm
        # For the current permutation, get the prefix sums
        sc1 = sum_c[c1]
        sc2 = sum_c[c2]
        sc3 = sum_c[c3]
        # Initialize min_prefix as sum_c1[a] - sum_c2[a]
        min_prefix = sc1[0] - sc2[0]  # a=0
        current_min = min_prefix + sc2[0] - sc3[0]
        min_cost = current_min
        for b in range(1, n + 1):
            # Update min_prefix
            current_prefix = sc1[b] - sc2[b]
            if current_prefix < min_prefix:
                min_prefix = current_prefix
            # Compute current cost
            current_cost = min_prefix + sc2[b] - sc3[b]
            if current_cost < min_cost:
                min_cost = current_cost
        total_cost = min_cost + sc3[n]
        if total_cost < min_total:
            min_total = total_cost

    print(min_total)


if __name__ == "__main__":
    main()
