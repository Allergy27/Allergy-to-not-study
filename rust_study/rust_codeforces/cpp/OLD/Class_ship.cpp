/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Class_ship.cpp
 *@date      2024/08/28 10:15:00
 */
#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, res = 0, k = 0;
    string input;
    cout << "人数:"; //必要的输入说明
    cin >> n;
    vector<int> stu(n), ans(n); //并查集数组模拟实现，ans用于统计
    unordered_map<string, int> surname; //姓
    unordered_map<string, int> name; //名

    //并查集部分
    auto find = [&](int k)->int {
        int x = k;
        while(stu[x] != x)x = stu[x];
        return x;
        };

    cout << "按空格分割输入一行人名（仅支持中文名）：\n";
    for(int j = 0;j < n;++j) {
        cin >> input;
        string a = input.substr(0, 2), b = input.substr(2); //a:姓氏 b:名字
        if(!surname.count(a) && !name.count(b)) { //姓名不存在
            stu[j] = k++;
            surname[a] = k, name[b] = k;
        }
        else if(surname.count(a) ^ name.count(b)) { //姓名其一存在
            if(surname.count(a))stu[j] = find(surname[a]), name[b] = find(surname[a]);
            else stu[j] = find(name[b]), surname[a] = find(name[b]);
        }
        else stu[j] = find(surname[a]), stu[find(name[b])] = find(surname[a]), name[b] = find(surname[a]);
    }

    for(int j = 0; j < n;++j)++ans[find(j)]; //合并便于统计
    for(auto x : ans)res += (x + 1) >> 1; //根据规律运算
    cout << res;
    return 0;
}