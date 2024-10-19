class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int i,j,k,x,n=nums.size();
        sort(nums.begin(),nums.end());
        for(i=0;i<n-2;++i){
            if(i>0&&nums[i]==nums[i-1])continue;
            if(nums[i]+nums[i+1]+nums[i+2]>0)break;
            if(nums[i]+nums[n-1]+nums[n-2]<0)continue;
            k=n-1;
            j=i+1;
            while(j<k){
                int Sum=nums[i]+nums[j]+nums[k];
                if(Sum<0)++j;
                else if(Sum>0)--k;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(++j<k&&nums[j]==nums[j-1]);
                    while(--k>j&&nums[k]==nums[k+1]);
                }
            }
        }
        return ans;
    }
};