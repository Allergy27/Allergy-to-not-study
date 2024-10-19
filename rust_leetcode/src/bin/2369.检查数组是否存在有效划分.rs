/*
 * @lc app=leetcode.cn id=2369 lang=rust
 *
 * [2369] 检查数组是否存在有效划分
 */

// @lc code=start
impl Solution {
    pub fn valid_partition(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut qwq: Vec<bool> = vec![false; n + 1];
        qwq[0]=true;
        for i in 1..n{
            if qwq[i - 1] && nums[i] == nums[i - 1] ||
                i > 1 && qwq[i - 2] && (nums[i] == nums[i - 1] && nums[i] == nums[i - 2] ||
                    nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2) {
                        qwq[i+1]=true;
                    }
        }
        qwq[n]
    }
}
// @lc code=end
