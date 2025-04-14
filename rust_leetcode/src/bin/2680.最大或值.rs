/*
 * @lc app=leetcode.cn id=2680 lang=rust
 * @lcpr version=30104
 *
 * [2680] 最大或值
 */

// @lc code=start
impl Solution {
    pub fn maximum_or(nums: Vec<i32>, k: i32) -> i64 {
        let n = nums.len();
        let mut pre = vec![0; n];
        let mut suf = vec![0; n];

        for i in 1..n {
            pre[i] = pre[i - 1] | nums[i - 1];
        }
        for i in (0..n - 1).rev() {
            suf[i] = suf[i + 1] | nums[i + 1];
        }
        (0..n).fold(0, |ans, i| ans.max((nums[i] << k | pre[i] | suf[i]) as i64))
    }
}
// @lc code=end

/*
// @lcpr case=start
// [12,9]\n1\n
// @lcpr case=end

// @lcpr case=start
// [8,1,2]\n2\n
// @lcpr case=end

 */
