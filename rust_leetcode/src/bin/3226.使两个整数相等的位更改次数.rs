/*
 * @lc app=leetcode.cn id=3226 lang=rust
 * @lcpr version=20002
 *
 * [3226] 使两个整数相等的位更改次数
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn min_changes(mut n: i32, mut k: i32) -> i32 {
        let mut ans = 0;
        while n > 0 || k > 0 {
            let (x, y) = (n & 1, k & 1);
            if x == 0 && y == 1 {
                return -1;
            } else if (x ^ y) == 1 {
                ans += 1;
            }
            n >>= 1;
            k >>= 1;
        }
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// 13\n4\n
// @lcpr case=end

// @lcpr case=start
// 21\n21\n
// @lcpr case=end

// @lcpr case=start
// 14\n13\n
// @lcpr case=end

 */
