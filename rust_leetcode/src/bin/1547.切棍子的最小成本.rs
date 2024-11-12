/*
 * @lc app=leetcode.cn id=1547 lang=rust
 * @lcpr version=20003
 *
 * [1547] 切棍子的最小成本
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn min_cost(n: i32, mut cuts: Vec<i32>) -> i32 {
        cuts.push(0);
        cuts.push(n);
        cuts.sort_unstable();
        let n = cuts.len();
        const INF: i32 = 1_000_000_000;
        let mut dp = vec![vec![0; n]; n];
        for i in (0..n - 2).rev() {
            for j in i + 2..n {
                let mut res = INF;
                for k in i + 1..j {
                    res = res.min(dp[i][k] + dp[k][j]);
                }
                dp[i][j] = res - cuts[i] + cuts[j]
            }
        }
        dp[0][n - 1]
    }
}
// @lc code=end

/*
// @lcpr case=start
// 7\n[1,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// 9\n[5,6,1,4,2]\n
// @lcpr case=end

 */
