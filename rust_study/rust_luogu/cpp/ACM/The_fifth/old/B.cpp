#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int m;
    cin >> m;
    while (m--) {
        int n;
        cin >> n;
        vector<int> qwq(n);//创建数组
        for (auto &x:qwq) cin >> x;
        if (qwq[0] != n) {//如果第一个不是最后一个肯定不行
            cout << "NO" << '\n';
            continue;
        }
        vector<int> qaq;
        for (int i = n-1; i >= 0; --i)//根据性质验证
            while (qaq.size() < qwq[i])qaq.emplace_back(i+1);//如果后面长度要求比当前高，就多打印一个
        bool flag = true;//哨兵
        for (int i = 0; i < n; i++){
            if (qwq[i] != qaq[i]){
                cout<<"NO"<<'\n';
                flag=false;
                break;
            }
        }
        if(flag)cout<<"YES"<<'\n';
    }
    getchar();getchar();
    return 0;
}