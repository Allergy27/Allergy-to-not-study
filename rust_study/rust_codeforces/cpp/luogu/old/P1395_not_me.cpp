#include<bits/stdc++.h>
using namespace std;
vector <int> g[123456];
bool vis[123456];
int v;
bool Visit[123456];
int team[100001];
int ans = 100001, n, d;
int DFS(int now) {
    int res = 0, sum = 1;       // res记录u的最大子树的节点数，sum记录以u为根的树中的所有的节点数（从下开始去除上一半，n-sum表示u上面部分的节点数，初始化为1表示当前只有结点自身）
    Visit[now] = true;            // 标记u这个点被搜过

    for(int i = 0;i < g[now].size();i++) {
        int j = g[now][i];
        if(!Visit[g[now][i]]) {              // 如果没有被搜过
            int s = DFS(j);         // s是以j为根的子树的结点数
            res = max(res, s);      // 记录u的最大子树的结点
            sum += s;
                          // 累加u的各子树的结点数
        }
    }
    if(max(res, n - sum) < ans || max(res, n - sum) == ans && now < v) {
        ans = max(res, n - sum);
        v = now;
 //   cout<<now<<" "<<ans<<" "<<max(res, n - sum)<<endl;;
//	cout<<"res"<<":"<<res<<"now:"<<now<<"ans:"<<sum<<endl;;  
        return sum;
    }
}
void dfs(int now, int dis) {
    int maxx = 0;
    vis[now] = 1;//标记 
    //if(dis==d) return;
    //cout<<"now:"<<now<<" size: "<<g[now].size()<<endl; 
    for(int i = 0;i < g[now].size();i++) {
        if(!vis[g[now][i]]) {
            ans += dis;
            dfs(g[now][i], dis + 1);

        }
    }
}
int main() {
    cin >> n;

    for(int i = 1;i < n;i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1);
//	cout<<v<<" ";
//	for(int i=1;i<=n;i++)
//	{
//		cout<<team[i]<<" ";
//	}
    memset(vis, false, sizeof(vis));
    ans = 0;
    dfs(v, 1);

    cout << v << ' ' << ans;
    return 0;
}