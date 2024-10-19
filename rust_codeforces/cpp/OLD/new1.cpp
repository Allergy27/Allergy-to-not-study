#include<iostream>
#include<string>

int main() {
    using namespace std;
    string s = "Hello";
    for(int i = 0;i<s.size();++i) {
        int j = s[i]-'0';
        cout<<j&10;
    }
    cout<<s<<endl;
    cin>>s;
    return 0;
}