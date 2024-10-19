/*
 * @lc app=leetcode.cn id=464 lang=rust
 * @lcpr version=20002
 *
 * [464] 我能赢吗
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn can_i_win(max_choosable_integer: i32, desired_total: i32) -> bool {
        if max_choosable_integer * (max_choosable_integer + 1) / 2 < desired_total {
            return false;
        }
        if desired_total <= max_choosable_integer {
            return true;
        }
        let mut dp = vec![0; 1 << (max_choosable_integer + 1)];
        Self::f(
            &mut dp,
            max_choosable_integer as usize,
            (1 << (max_choosable_integer + 1)) - 1,
            desired_total,
        )
    }
    pub fn f(dp: &mut Vec<i32>, n: usize, status: usize, rest: i32) -> bool {
        if rest <= 0 {
            return false;
        }
        if dp[status] != 0 {
            return dp[status] == 1;
        }
        let mut ans = false;
        for i in 1..=n {
            if status & (1 << i) != 0 && !Self::f(dp, n, status ^ (1 << i), rest - i as i32) {
                ans = true;
                break;
            }
        }
        dp[status] = if ans { 1 } else { -1 };
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// 10\n11\n
// @lcpr case=end

// @lcpr case=start
// 10\n0\n
// @lcpr case=end

// @lcpr case=start
// 10\n1\n
// @lcpr case=end

 */
