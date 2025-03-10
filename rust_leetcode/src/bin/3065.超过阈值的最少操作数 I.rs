/*
 * @lc app=leetcode.cn id=3065 lang=rust
 * @lcpr version=20004
 *
 * [3065] 超过阈值的最少操作数 I
 */

// @lcpr-template-start

use std::cmp::Reverse;

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        let mut qwq = std::collections::BinaryHeap::from_iter(nums.iter().map(Reverse));
        let mut ans = 0;
        while let Some(Reverse(x)) = qwq.pop() {
            if *x >= k {
                break;
            }
        }
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// [2,11,10,1,3]\n10\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,4,9]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,4,9]\n9\n
// @lcpr case=end

 */
