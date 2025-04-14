/*
 * @lc app=leetcode.cn id=1922 lang=rust
 * @lcpr version=30104
 *
 * [1922] 统计好数字的数目
 */

// @lc code=start
impl Solution {
    pub fn count_good_numbers(n: i64) -> i32 {
        const MOD: i64 = 1e9 + 7;
        let qpow = |x: i64, y: i64| {
            let mut cnt = y;
            let mut tmp = y;
            let mut ans = x;
            while (cnt > 0) {
                tmp = (tmp * tmp) % MOD;
                if cnt & 1 == 1 {
                    ans = (ans * tmp) % MOD;
                }
                cnt >>= 1;
            }
            return ans;
        };
        if (n % 2 == 1) {
            qpow(20, n / 2);
        } else {
            (qpow(20, n / 2) * 5) % MOD
        }
    }
}
// @lc code=end

/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 50\n
// @lcpr case=end

 */
