#include<bits/stdc++.h>//万能库写好了
#define ll long long
//以及ll代替long long节约打字数

using namespace std; //命名空间也是

void solve() { //解题部分
    int n, x, y;
    cin>>n>>x>>y;
    vector<vector<int>>qwq(n+1); //下标从1开始，所以n+1
    for(int i = 0;i<n-1;++i) {
        int U, V;
        cin>>U>>V;
        qwq[U].emplace_back(V); //边相连
        qwq[V].emplace_back(U); //边相连
    }
    vector<int>qaq(n+1, -1); //记录是不是找过了
    queue<int> que; //队列实现BFS

    qaq[x] = 0; //从x开始找，x为0
    que.push(x); //入队

    while(!que.empty()) {
        int fa = que.front(); //找父亲
        que.pop(); //出队

        for(int son : qwq[fa]) { //找儿子
            if(qaq[son]!=-1)continue; //之前找过了就找下一个
            qaq[son] = fa; //孩子和父亲连接
            que.push(son); //孩子入队
        }
    }
    int i = y; //找完了
    vector<int>ans; //存放答案
    while(qaq[i]) { //qaq[i]非空
        ans.emplace_back(i); //添加
        i = qaq[i]; //找下一个
    }
    ans.emplace_back(x); //添加开头
    for(int i = ans.size()-1;i>=0;--i)cout<<ans[i]<<' '; //输出
}

int main() {
    int t = 1; //如果有多个样例就把下面那个取消了

    //cin>>t;
    while(t--)solve();
    getchar();getchar();
    return 0;
}