/*
 * @lc app=leetcode.cn id=1599 lang=rust
 *
 * [1599] 经营摩天轮的最大利润
 */

// @lc code=start
impl Solution {
    pub fn min_operations_max_profit(
        customers: Vec<i32>,
        boarding_cost: i32,
        running_cost: i32,
    ) -> i32 {
        let mut qwq = (-1, -1);
        let mut res = (0, 0); //准备登机的 登机了的
        let mut i = 0;
        while i < customers.len() || res.0 > 0 {
            res.0 += if i < customers.len() { customers[i] } else { 0 };
            res = (res.0 - 4.min(res.0), res.1 + 4.min(res.0));
            i += 1;
            if qwq.1 < res.1 * boarding_cost - (i as i32) * running_cost {
                qwq = (i as i32, res.1 * boarding_cost - (i as i32) * running_cost)
            }
        }
        qwq.0
    }
}
// @lc code=end
