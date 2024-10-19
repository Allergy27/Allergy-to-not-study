//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace leetcode/q_2.rs
//@data      2024/10/13 11:08:05
struct Solution;
impl Solution {
    pub fn count_winning_sequences(s: String) -> i32 {
        let n = s.len();
        let mut dp = vec![vec![vec![0; n * 2]; 3]; n];
        let count = |a: i32, b: i32| match (a, b) {
            (0, 2) => 1,
            (0, 1) => -1,
            (1, 0) => 1,
            (1, 2) => -1,
            (2, 1) => 1,
            (2, 0) => -1,
            _ => 0,
        };
        let qwq = s
            .chars()
            .map(|x| match x {
                'F' => 0,
                'W' => 1,
                'E' => 2,
                _ => unreachable!(),
            })
            .collect::<Vec<_>>();
        //方案
        //dp[i][j][t] i为转移到第i位，j为选择哪种操作,t为得分
        for i in 0..3 {
            dp[0][i as usize][(n as i32 + count(i, qwq[0])) as usize] = 1;
        }
        for i in 1..n {
            for j in 0..3 {
                let point = count(j as i32, qwq[i]);
                for t in 0..2 * n as i32 {
                    for k in 0..3 {
                        if k == j {
                            continue;
                        }
                        dp[i][j][t as usize] = (dp[i][j][t as usize]
                            + dp[i - 1][k][(t - point) as usize])
                            % 1000000007;
                    }
                }
            }
        }
        let mut ans = 0;
        for i in 0..3 {
            for j in n + 1..2 * n {
                ans = (ans + dp[n - 1][i][j]) % 1000000007;
            }
        }
        ans
    }
}
fn main() {
    Solution::count_winning_sequences("FW".to_string());
}
