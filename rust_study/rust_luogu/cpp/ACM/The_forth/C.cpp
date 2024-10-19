#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, i, j;
    cin >> n >> m >> j;
    if (m > n)i = 0;
    else i = (n - m) / j + 1;
    cout << i;
    getchar();getchar();
    return 0;
}