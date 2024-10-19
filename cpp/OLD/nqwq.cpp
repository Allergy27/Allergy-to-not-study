class Solution {
public:
    string minWindow(string s, string t) {
        int hash1[128] = { 0 }, hash2[128] = { 0 };
        int k = 0;
        for(auto a : t)if(hash1[a]++ == 0)k++;
        int len = INT_MAX;
        int q = -1;
        for(int left = 0, right = 0, count = 0;right < s.size();right++) {
            char ch = s[right];
            hash2[ch]++;
            if(hash2[ch] == hash1[ch])count++;
            while(count == k) {
                if(len > right - left + 1) {
                    len = min(len, right - left + 1);
                    q = left;
                }
                char out = s[left];
                left++;
                if(hash2[out] == hash1[out])count--;
                hash2[out]--;
            }
        }
        if(q == -1)return "";
        else return s.substr(q, len);
    }
};