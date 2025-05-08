/*
 * @lc app=leetcode.cn id=2338 lang=rust
 * @lcpr version=30104
 *
 * [2338] 统计理想数组的数目
 */

// @lc code=start

impl Solution {
    pub fn ideal_arrays(n: i32, max_value: i32) -> i32 {
        // 预计算所有数的质因数指数
        let mut exp = vec![Vec::new(); (max_value + 1) as usize];

        for x in 2..=max_value {
            let mut t = x;
            let mut i = 2;
            while i * i <= t {
                let mut e = 0;
                while t % i == 0 {
                    e += 1;
                    t /= i;
                }
                if e > 0 {
                    exp[x as usize].push(e as i64);
                }
                i += 1;
            }
            if t > 1 {
                exp[x as usize].push(1);
            }
        }
        const MOD: i64 = 1_000_000_007;
        let mut c = vec![vec![0; 27 + 1]; n as usize + 27];
        c[0][0] = 1;
        c[1][0] = 1;
        c[1][1] = 1;
        for i in 2..n as usize + 27 {
            c[i][0] = 1;
            for j in 1..=i.min(27) {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
            }
        }
        let mut ans = 0;
        for i in 2..=max_value as usize {
            let mut res = 1;
            for e in &exp[i] {
                res = (res * c[n as usize + *e as usize - 1][*e as usize]) % MOD;
            }
            ans = (ans + res) % MOD;
        }
        ans as i32 + 1
    }
}
// @lc code=end

/*
// @lcpr case=start
// 9316\n9559\n
// @lcpr case=end

// @lcpr case=start
// 10000\n10000\n
// @lcpr case=end

 */
