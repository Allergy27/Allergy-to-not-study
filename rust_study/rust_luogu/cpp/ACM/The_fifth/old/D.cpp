#include<bits/stdc++.h>

using namespace std;

int main(){
     int N, X, Y;
    cin >> N >> X >> Y;
    vector<vector<int>> qwq(N + 1);
    for (int i = 0; i < N - 1; i++){
        int U, V;
        cin >> U >> V;
        qwq[U].emplace_back(V);//连边
        qwq[V].emplace_back(U);//连边
    }

    vector<int> dist(N + 1, -1);//记录是不是找过了
    queue<int> que;//BFS的队列实现

    dist[X] = 0;//从第x个开始找
    que.push(X);//入队

    while (!que.empty()){//BFS
        int v = que.front();
        que.pop();

        for (int nv : qwq[v]){//找孩子
            if (dist[nv] != -1) continue;//已经找过,退出
            dist[nv] = v;
            que.push(nv);

        }
    }
    int i = Y;
    vector<int> ans;//存放答案
    while (dist[i] != 0){
        ans.emplace_back(i);
        i = dist[i];
    }
    ans.emplace_back(X);
    reverse(ans.begin(), ans.end());
    for (auto &x : ans) cout << x << " ";
}
