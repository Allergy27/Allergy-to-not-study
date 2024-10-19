#include<stdio.h>

int main() {
    int n, m;
    double da;
    char useless[32];
    const char DaDa[5] = { 'D', 'a', 'D', 'a', '\0' };
    scanf("%d", &n);
    double qwq[102];
    for(int i = 0;i < n;++i)scanf("%s", useless);
    scanf("%d", &m);
    while(m--) {
        for(int i = 0;i < n;++i) {
            scanf("%lf%s", &qwq[i], useless);
            for(int j = 0;j <= 4;++j) {
                if(useless[j] != DaDa[j])break;
                if(useless[j] == 0)da = qwq[i];
            }
        }
        for(int i = 0;i < n;++i)
            for(int j = i;j > 0;--j) {
                double tmp;
                if(qwq[j] > qwq[j - 1]) {
                    tmp = qwq[j];
                    qwq[j] = qwq[j - 1];
                    qwq[j - 1] = tmp;
                }
            }
        for(int i = 0;i < n;++i) {
            if(qwq[i] == da) {
                printf("%d\n", i + 1);
                break;
            }
        }
    }
    getchar();getchar();
    return 0;
}