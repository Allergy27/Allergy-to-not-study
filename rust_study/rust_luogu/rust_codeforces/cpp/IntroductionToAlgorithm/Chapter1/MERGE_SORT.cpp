#include<bits/stdc++.h>

using namespace std;

void MERGE_SORT(vector<int> &, int, int);

int main() {
    int n;
    cout << "Please enter the lenth of what u want to sort:" << endl;
    cin >> n;
    vector<int>qwq(n);
    for(auto &x : qwq)cin >> x;
    MERGE_SORT(qwq, 0, n - 1);
    for(auto &x : qwq)cout << x << ' ';
    getchar();getchar();
    return 0;
}
void MERGE_SORT(vector<int> &list, int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;
        MERGE_SORT(list, p, q);
        MERGE_SORT(list, q + 1, r);
        vector<int>L;
        vector<int>R;
        for(int x = p;x <= q;++x)L.emplace_back(list[x]);
        for(int x = q + 1;x <= r;++x)R.emplace_back(list[x]);
        int a = 0, b = 0;
        for(int t = p;t <= r;++t) {
            if(b == r - q) list[t] = L[a++];
            else if(a == q - p + 1) list[t] = R[b++];
            else if(L[a] <= R[b]) list[t] = L[a++];
            else list[t] = R[b++];
        }
    }
}