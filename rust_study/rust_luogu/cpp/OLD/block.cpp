#include<iostream>
#include<random>

int main() {
    int n;
    std::cin>>n;
    int List[n*n];
    for(int i = 0;i<n;++i)
        for(int j = 0;j<n;++j) {
            List[i+j] = i+j+1;
        }
    for(int k = 0;k<n*n;++k) {
        int p;int q;int o;
        std::uniform_int_distribution<int> p(0, n*n-1);
        std::uniform_int_distribution<int> q(0, n*n-1);
        o = List[p];List[p] = List[q];List[q] = o;
    }
    for(int i = 0;i<n;++i) {
        for(int j = 0;j<n;++j) {
            std::cout<<List[i+j]<<'\t';
        }
        std::cout<<std::endl;
    }

}