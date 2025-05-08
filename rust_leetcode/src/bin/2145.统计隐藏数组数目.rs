/*
 * @lc app=leetcode.cn id=2145 lang=rust
 * @lcpr version=30104
 *
 * [2145] 统计隐藏数组数目
 */

// @lc code=start
impl Solution {
    pub fn number_of_arrays(differences: Vec<i32>, lower: i32, upper: i32) -> i32 {
        let n = differences.len();
        let mut qwq = vec![0i64; n + 1];
        for i in 1..=n {
            qwq[i] = qwq[i - 1] + differences[i - 1] as i64;
        }
        (upper - lower - (qwq.iter().max().u - min) as i32 + 1).max(0)
    }
}
// @lc code=end

/*
// @lcpr case=start
// [1,-3,4]\n1\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,-4,5,1,-2]\n-4\n5\n
// @lcpr case=end

// @lcpr case=start
// [83702,-5216]\n-82788\n14602
// @lcpr case=end

 */
