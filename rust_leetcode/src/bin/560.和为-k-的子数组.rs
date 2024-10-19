/*
 * @lc app=leetcode.cn id=560 lang=rust
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
use std::collections::HashMap;
impl Solution {
    pub fn subarray_sum(nums: Vec<i32>, k: i32) -> i32 {
        let (mut pre, mut ans) = (0, 0);
        let mut qwq = HashMap::from([(0, 1)]);
        for x in nums {
            pre += x;
            if let Some(&v) = qwq.get(&(pre - k)) {
                ans += v;
            }
            qwq.entry(pre).and_modify(|x| *x += 1).or_insert(1);
        }
        ans
    }
}
// @lc code=end
