/*
 * @lc app=leetcode.cn id=128 lang=rust
 *
 * [128] 最长连续序列
 */

// @lc code=start
use std::collections::HashSet;
impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        let qwq: HashSet<i32> = nums.into_iter().collect();
        let mut ans = 0;
        for &i in qwq.iter() {
            if !qwq.contains(&(i - 1)) {
                let mut now = i;
                let mut len = 1;
                while qwq.contains(&(now + 1)) {
                    now += 1;
                    len += 1;
                }
                ans = ans.max(len);
            }
        }
        ans
    }
}
// @lc code=end
