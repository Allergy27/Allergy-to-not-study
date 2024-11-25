/*
 * @lc app=leetcode.cn id=3233 lang=rust
 * @lcpr version=20003
 *
 * [3233] 统计不是特殊数字的数字数量
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn non_special_count(l: i32, r: i32) -> i32 {
        let mut ans = r - l + 1;
        let nr = (r as f64).sqrt() as usize;
        let mut is_prime = vec![true; nr + 1];
        let mut prime = Vec::new();
        for i in 2..=nr {
            if is_prime[i] {
                if i * i >= l {
                    ans -= 1;
                }
                prime.push(i);
            }
            for &j in &prime {
                if i * j > nr {
                    break;
                }
                is_prime[i * j] = false;
                if i % j == 0 {
                    break;
                }
            }
        }
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// 5\n7\n
// @lcpr case=end

// @lcpr case=start
// 4\n16\n
// @lcpr case=end

 */
