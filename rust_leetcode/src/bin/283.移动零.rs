/*
 * @lc app=leetcode.cn id=283 lang=rust
 *
 * [283] 移动零
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn move_zeroes(nums: &mut Vec<i32>) {
        let mut l = 0;
        for r in 0..nums.len() {
            if nums[r] != 0 {
                if l != r {
                    nums.swap(l, r)
                }
                l += 1;
            }
        }
    }
}
// @lc code=end
