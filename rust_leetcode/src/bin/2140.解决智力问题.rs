/*
 * @lc app=leetcode.cn id=2140 lang=rust
 * @lcpr version=30104
 *
 * [2140] 解决智力问题
 */

// @lc code=start
impl Solution {
    pub fn most_points(questions: Vec<Vec<i32>>) -> i64 {
        let mut questions = questions;
        let n = questions.len();
        let mut ans = vec![0; n + 1];
        for i in 0..n {
            let (x, y) = (questions[i][0], questions[i][1]);
            let tmp = n.min(i + y as usize + 1);
            ans[i + 1] = ans[i + 1].max(ans[i]);
            ans[tmp] = ans[tmp].max(ans[i] + x as i64);
        }
        ans[n]
    }
}
// @lc code=end

/*
// @lcpr case=start
// [[3,2],[4,3],[4,4],[2,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,2],[3,3],[4,4],[5,5]]\n
// @lcpr case=end

// @lcpr case=start
// [[21,5],[92,3],[74,2],[39,4],[58,2],[5,5],[49,4],[65,3]]\n
// @lcpr case=end
 */
