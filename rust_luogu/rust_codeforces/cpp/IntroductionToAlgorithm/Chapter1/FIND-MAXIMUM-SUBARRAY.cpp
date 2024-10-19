#include<bits/stdc++.h>

using namespace std;

vector<int> FIND_MAXIMUM_SUBARRAY(vector<int>, int, int);

int main() {
    int n, m, i, j;
    cin >> n;
    getchar();getchar();
    return 0;
}
vector<int> FIND_MAXIMUM_SUBARRAY(vector<int> A, int low, int high) {
    if(high == low)return { low, high, A[low] };
    int mid = (low + high) / 2;
    vector<int>left = { 0, 0, 0 };
    vector<int>right = { 0, 0, 0 };
    left = FIND_MAXIMUM_SUBARRAY(A, low, mid);
    right = FIND_MAXIMUM_SUBARRAY(A, mid + 1, high);
    //这里我们依然把函数(FINE_MAX_CROSSING_SUBARRAY)单独编写;
    vector<int>cross = { 0, 0, 0 };
    int left_sum = INT_MIN, Sum = 0;
    for(int i = mid;i >= low;--i) {
        Sum += A[i];
        if(Sum > left_sum) {
            left_sum = Sum;
            cross[0] = i;
        }
    }
    int right_sum = INT_MIN;
    Sum = 0;
    for(int i = mid + 1;i < high;++i) {
        Sum += A[i];
        if(Sum > right_sum) {
            right_sum = Sum;
            cross[1] = i;
        }
    }
    cross[2] = left_sum + right_sum;
    //到这里找跨越的部分就找完了
    if(left[2] >= right[2] && left[2] >= cross[2])return left;
    else if(right[2] >= left[2] && right[2] >= cross[2]) return right;
    return cross;
}