/*
 * @lc app=leetcode.cn id=1 lang=rust
 *
 * [1] 两数之和
 */

// @lc code=start
use std::collections::HashMap;
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut qwq = HashMap::new();
        nums.iter().enumerate().fold(vec![0, 0], |ans, (j, &x)| {
            if let Some(&i) = qwq.get(&(target - x)) {
                vec![i, j as i32]
            } else {
                qwq.insert(x, j as i32);
                ans
            }
        })
    }
}
// @lc code=end
