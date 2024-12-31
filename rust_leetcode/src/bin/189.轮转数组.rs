/*
 * @lc app=leetcode.cn id=189 lang=rust
 * @lcpr version=20004
 *
 * [189] 轮转数组
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let k = k as usize % nums.len(); // 轮转 k 次等于轮转 k%n 次
        nums.reverse();
        nums[..k].reverse();
        nums[k..].reverse();
    }
}
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [-1,-100,3,99]\n2\n
// @lcpr case=end

 */
