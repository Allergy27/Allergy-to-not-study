/*
 * @lc app=leetcode.cn id=1450 lang=rust
 *
 * [1450] 在既定时间做作业的学生人数
 */

// @lc code=start
impl Solution {
    pub fn busy_student(start_time: Vec<i32>, end_time: Vec<i32>, query_time: i32) -> i32 {
        let len = start_time.len();
        (0..len).fold(0, |ans, i| {
            ans + if (start_time[i] <= query_time && query_time <= end_time[i]) {
                1
            } else {
                0
            }
        })
    }
}
// @lc code=end
