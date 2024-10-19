/*
 * @lc app=leetcode.cn id=1052 lang=rust
 *
 * [1052] 爱生气的书店老板
 */

// @lc code=start
impl Solution {
    pub fn max_satisfied(customers: Vec<i32>, grumpy: Vec<i32>, minutes: i32) -> i32 {
        let mut ans = (0..customers.len()).fold(0, |x, i| {
            x + if grumpy[i] == 0 || i < minutes {
                customers[i]
            } else {
                0
            }
        });
        (minutes..customers.len()).fold([ans, ans], |tmp, i| {
            tmp[0] += customers[i] * grumpy[i] - customers[i - minutes] * grumpy[i - minutes];
            [tmp[0], tmp[1].max(tmp[0])]
        })
    }
}
// @lc code=end
