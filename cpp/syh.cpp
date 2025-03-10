// copyright qwq
#include <iostream>  // NOLINT
#include <queue>
int tot;
using namespace std;  // NOLINT
int main() {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        if (m != 0) {  // 非0入队
            if (q.size() <= 9)
                q.push(m);
            else
                printf("Full ");  // 错在这里
        } else {
            if (!q.empty()) {
                int x = q.front();
                q.pop();
                printf("%d ", x);
            } else {
                printf("EMPTY ");
            }
        }
    }
    printf("\n");
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        printf("%d ", x);
    }
    return 0;
}
