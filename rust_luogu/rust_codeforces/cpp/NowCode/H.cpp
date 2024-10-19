/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace NowCode\H.cpp
 *@data      2023/11/22 16:11:21
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() { //解题部分
    int n, m;
    cin >> n >> m;
    if(m==0){
        cout<<-1;
        return;
    }
    struct VC {
        int edge;
        int fee;
    };

    vector<vector<VC>>qwq(n + 1); //下标从1开始，所以n+1
    for(int i = 0;i < m;++i) {
        int U, V, R;
        cin >> U >> V >> R;
        VC Ump = { U, R };
        VC Vmp = { V, R };
        qwq[U].emplace_back(Vmp); //边相连
        qwq[V].emplace_back(Ump); //边相连
    }
    VC tmp = { -1, 0 };
    vector<VC>qaq(n + 1, tmp); //记录是不是找过了
    queue<int> que; //队列实现BFS

    qaq[1].edge = 0; //从x开始找，x为0
    que.push(1); //入队
    while(!que.empty()) {
        int fa = que.front(); //找父亲
        que.pop(); //出队

        for(VC son : qwq[fa]) { //找儿子
            if(qaq[son.edge].edge == -1) { //之前没找过
                qaq[son.edge].edge = fa; //孩子和父亲连接
                qaq[son.edge].fee += qaq[fa].fee + son.fee;
                que.push(son.edge); //孩子入队
            }
            else if(qaq[son.edge].fee > qaq[fa].fee + son.fee) {
                qaq[son.edge].edge = fa;
                qaq[son.edge].fee = qaq[fa].fee + son.fee;
                que.push(son.edge);
            }
        }
    }
    int i = n; //找完了
    vector<int>ans; //存放答案
    if(qaq[i].edge==-1) {
        cout << -1;
        return;
    }
    while(qaq[i].edge) { //qaq[i]非空
        ans.emplace_back(i); //添加
        i = qaq[i].edge; //找下一个
    }
    ans.emplace_back(1); //添加开头
    for(int i = ans.size() - 1;i >= 0;--i)cout << ans[i] << ' '; //输出
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}