#include <stdio.h>
#include <stdlib.h>
#define INF 2000000005
#define MOD 1000000007

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int t;
    scanf("%d", &t);
    char result[1000000];
    int pos = 0;

    while (t--) {
        int n, m, q;
        scanf("%d %d %d", &n, &m, &q);

        if (m > 10000) {
            printf("Error: m exceeds allowed array size.\n");
            return 1;
        }

        int b[m];
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        qsort(b, m, sizeof(int), cmp);

        while (q--) {
            int x;
            scanf("%d", &x);
            if (x < b[0]) {
                pos += sprintf(result + pos, "%d\n", b[0] - 1);
            } else if (x > b[m - 1]) {
                pos += sprintf(result + pos, "%d\n", n - b[m - 1]);
            } else {
                int p = 0;
                while (p < m && b[p] <= x) {
                    p++;
                }
                if (p == 0 || p >= m) {
                    pos += sprintf(result + pos, "0\n");
                } else {
                    int y = b[p] - b[p - 1] - 1;
                    pos += sprintf(result + pos, "%d\n", (y + 1) / 2);
                }
            }
        }
    }
    printf("%s", result);
    return 0;
}
