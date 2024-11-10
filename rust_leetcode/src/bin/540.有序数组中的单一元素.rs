/*
 * @lc app=leetcode.cn id=540 lang=rust
 * @lcpr version=20003
 *
 * [540] 有序数组中的单一元素
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn single_non_duplicate(nums: Vec<i32>) -> i32 {
        nums[(0..nums.len() / 2)
            .position(|k| nums[k * 2] != nums[k * 2 + 1])
            .unwrap_or(nums.len() / 2)
            * 2]
    }
}
// @lc code=end

/*
// @lcpr case=start
// [1,1,2,3,3,4,4,8,8]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,7,7,10,11,11]\n
// @lcpr case=end

 */
