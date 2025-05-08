/*
 * @lc app=leetcode.cn id=2949 lang=rust
 * @lcpr version=30104
 *
 * [2949] 统计美丽子字符串 II
 */

// @lc code=start
impl Solution {
    pub fn beautiful_substrings(s: String, k: i32) -> i64 {
        let pre_sqrt = |n: i64| {
            let mut ans = 1;
            for i in 2..n {
                let i2 = i * i;
                if i2 > n {
                    break;
                }
                while n % i2 == 0 {
                    ans *= i;
                    n /= i2;
                }
                if n % i == 0 {
                    ans *= i;
                    n /= i;
                }
            }
            if n > 1 {
                ans * n
            } else {
                ans
            }
        };
        const AEIOU: i64 = 1065233;
        let k = pre_sqrt(k as i64 * 4);
        let mut cnt = std::collections::HashMap::new();
        cnt.insert((k - 1) << 16 | sum, 1);
        let n = s.len() as i64;
        let mut sum = n as i64;
        let mut ans = 0;
        for (i, x) in s.chars().enumerate() {
            let bit = (AEIOU >> (x as i64 - 'a' as i64)) & 1;
            sum += bit * 2 - 1;
            *cnt.entry((i % k) << 16 | sum).or_insert(0) += 1;
            ans += cnt[&((i % k) << 16 | sum)];
        }
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// "baeyh"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abba"\n1\n
// @lcpr case=end

// @lcpr case=start
// "bcdf"\n1\n
// @lcpr case=end

 */
