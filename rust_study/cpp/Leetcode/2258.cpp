#include<bits/stdc++.h>
using namespace std;
class Solution {
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m= grid.size(),n=grid[0].size();//记录长度
        //宽搜
        auto bfs= [&](vector<pair<int, int>> &posation) -> tuple<int, int, int> {
            vector<vector<int>> Time(m,vector<int>(n,-1));
            for(auto &[i,j]: posation) Time[i][j]=0;

            for(int t=1;!posation.empty();++t) {
                vector<pair<int,int>> movePosation;

                for(auto &[i,j]: posation) {
                    for(auto &[xp,yp]:dir) {
                        int x=xp+i,y=yp+j;

                        if(0<= x && x< m && 0<= y && y< n && grid[x][y]== 0 && Time[x][y]<0) {
                            Time[x][y]=t;
                            movePosation.emplace_back(x,y);
                        }

                    }
                }
                posation= move(movePosation);
            }
            return {Time[m-1][n-1],Time[m-2][n-1],Time[m-1][n-2]};
        };

        vector<pair<int,int>> people={{0,0}};
        auto [peopleTime,p1,p2]= bfs(people);
        if(peopleTime< 0) return -1;

        vector<pair<int,int>> fire;
        for(int i= 0; i< m; ++i)for(int j= 0; j< n; ++j)if(grid[i][j]== 1)fire.emplace_back(i,j);
        auto [fireTime,f1,f2]= bfs(fire);
        if(fireTime< 0) return 1000000000;

        int subt= fireTime- peopleTime;
        if(subt< 0) return -1;

        if(p1!= -1&& p1+ subt< f1|| p2!= -1&& p2+ subt< f2)return subt;
        return subt-1;
    }
};