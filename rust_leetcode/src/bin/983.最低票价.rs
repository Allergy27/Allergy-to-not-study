/*
 * @lc app=leetcode.cn id=983 lang=rust
 *
 * [983] 最低票价
 */

// @lc code=start
impl Solution {
    pub fn mincost_tickets(days: Vec<i32>, costs: Vec<i32>) -> i32 {
        let qwq: std::collections::HashSet<i32> = days.iter().cloned().collect();
        let qvq = days[days.len() - 1];
        let mut dp = vec![0; 366];
        for i in 1..=qvq {
            if !qwq.contains(&i) {
                dp[i as usize] = dp[(i - 1) as usize];
                continue;
            }
            dp[i as usize] = dp[(i - 1) as usize] + costs[0];
            dp[i as usize] = dp[i as usize].min(dp[(i - 7).max(0) as usize] + costs[1]);
            dp[i as usize] = dp[i as usize].min(dp[(i - 30).max(0) as usize] + costs[2]);
        }
        return dp[qvq as usize];
    }
}
// @lc code=end
