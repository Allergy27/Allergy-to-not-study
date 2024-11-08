/*
 * @lc app=leetcode.cn id=3254 lang=rust
 * @lcpr version=20003
 *
 * [3254] 长度为 K 的子数组的能量值 I
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn results_array(qwq: Vec<i32>, k: i32) -> Vec<i32> {
        let n = qwq.len();
        qwq.windows(k as usize)
            .map(|x| {
                if (1..x.len()).fold(true, |ans, p| x[p] == x[p - 1] + 1 && ans) {
                    *x.last().unwrap()
                } else {
                    -1
                }
            })
            .collect()
    }
}
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,3,2,5]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n4\n
// @lcpr case=end

// @lcpr case=start
// [3,2,3,2,3,2]\n2\n
// @lcpr case=end

 */
