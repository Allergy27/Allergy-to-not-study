/*
 * @lc app=leetcode.cn id=3096 lang=rust
 *
 * [3096] 得到更多分数的最少关卡数目
 */

// @lc code=start
impl Solution {
    pub fn minimum_levels(possible: Vec<i32>) -> i32 {
        let n = possible.len();
        let mut mid_sum = 0;
        let pre_num = (0..n)
            .map(|x| {
                mid_sum += if possible[x] == 0 { -1 } else { 1 };
                mid_sum
            })
            .collect::<Vec<i32>>();
        (0..n).fold(-1, |ans, i| {
            if ans == -1 && 2 * pre_num[i] > pre_num[n - 1] {
                i + 1
            } else {
                ans
            }
        })
    }
}
// @lc code=end
