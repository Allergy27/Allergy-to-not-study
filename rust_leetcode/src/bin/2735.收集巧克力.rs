/*
 * @lc app=leetcode.cn id=2735 lang=rust
 *
 * [2735] 收集巧克力
 */

// @lc code=start
impl Solution {
    pub fn min_cost(nums: Vec<i32>, x: i32) -> i64 {
        let n = nums.len();
        let mut s: Vec<i64> = (0..n).map(|v| v as i64 * x as i64).collect();
        nums.iter()
            .enumerate()
            .for_each(|(i, &v)| (i..n + i).for_each(|j| s[j - i] += v.min(nums[j % n]) as i64));
        *s.iter().min().unwrap()
    }
}
// @lc code=end
