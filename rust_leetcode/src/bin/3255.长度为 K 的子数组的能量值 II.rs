/*
 * @lc app=leetcode.cn id=3255 lang=rust
 * @lcpr version=20003
 *
 * [3255] 长度为 K 的子数组的能量值 II
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn results_array(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let n = nums.len();
        let mut ans = vec![-1; n - k as usize + 1];
        (0..=n).fold(1, |cnt, i| {
            if i != 0 && cnt >= k {
                ans[i - k as usize] = nums[i - 1];
            }
            if i == 0 || i == n || nums[i] != nums[i - 1] + 1 {
                1
            } else {
                cnt + 1
            }
        });
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// [5,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,38,39,75,76]\n20\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [2,3]\n1\n
// @lcpr case=end

 */
