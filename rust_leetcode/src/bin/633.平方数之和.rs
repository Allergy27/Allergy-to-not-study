/*
 * @lc app=leetcode.cn id=633 lang=rust
 * @lcpr version=20002
 *
 * [633] 平方数之和
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn judge_square_sum(c: i32) -> bool {
        let c = c as i64;
        let (mut l, mut r) = (0, 0);
        for i in 0..=c {
            if i * i >= c {
                r = i;
                break;
            }
        }
        while l <= r {
            let sum = l * l + r * r;
            if sum == c {
                return true;
            } else if sum < c {
                l += 1;
            } else {
                r -= 1;
            }
        }
        false
    }
}
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 214748364\n
// @lcpr case=end

 */
