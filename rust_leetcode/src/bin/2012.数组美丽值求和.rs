/*
 * @lc app=leetcode.cn id=2012 lang=rust
 * @lcpr version=30101
 *
 * [2012] 数组美丽值求和
 */

// @lc code=start
impl Solution {
    pub fn sum_of_beauties(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut pre = vec![nums[0]; n];
        let mut suf = vec![nums[n - 1]; n];
        for i in 1..n {
            pre[i] = pre[i - 1].max(nums[i])
        }
        for i in (0..n - 1).rev() {
            suf[i] = suf[i + 1].min(nums[i])
        }
        (1..n - 1).fold(0, |ans, i| {
            ans + if pre[i - 1] < nums[i] && nums[i] < suf[i + 1] {
                2
            } else if nums[i - 1] < nums[i] && nums[i] < nums[i + 1] {
                1
            } else {
                0
            }
        })
    }
}
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

 */
