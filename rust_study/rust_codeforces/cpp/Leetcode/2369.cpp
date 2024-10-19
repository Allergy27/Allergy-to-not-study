int n = nums.size();
vector<bool>qwq(n + 1);
qwq[0] = true;
for(int i = 1; i < n; i++)
    if(f[i - 1] && nums[i] == nums[i - 1] ||
        i > 1 && f[i - 2] && (nums[i] == nums[i - 1] && nums[i] == nums[i - 2] ||
            nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2))
        qwq[i + 1] = true;

