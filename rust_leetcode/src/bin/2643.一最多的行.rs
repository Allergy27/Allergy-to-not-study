/*
 * @lc app=leetcode.cn id=2643 lang=rust
 * @lcpr version=30104
 *
 * [2643] 一最多的行
 */

// @lc code=start
impl Solution {
    pub fn row_and_maximum_ones(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let mut ans = 0;
        let mut max = 0;
        for (i, a) in mat.iter().enumerate() {
            let tmp = a.iter().sum();
            if tmp > max {
                ans = i;
                max = tmp;
            }
        }
        vec![ans as _, max as _]
    }
}
// @lc code=end

/*
// @lcpr case=start
// [[0,1],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0],[0,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,1],[0,0]]\n
// @lcpr case=end

 */
