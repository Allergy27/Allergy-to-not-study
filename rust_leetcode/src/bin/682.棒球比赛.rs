/*
 * @lc app=leetcode.cn id=682 lang=rust
 *
 * [682] 棒球比赛
 */

// @lc code=start
impl Solution {
    pub fn cal_points(operations: Vec<String>) -> i32 {
        let mut qwq = vec![];
        for x in operations.into_iter() {
            match x.as_str() {
                "+" => {
                    let i = qwq.len();
                    qwq.push(qwq[i - 1] + qwq[i - 2]);
                }
                "D" => {
                    qwq.push(qwq.last().unwrap() * 2);
                }
                "C" => {
                    qwq.pop();
                }
                _ => {
                    qwq.push(x.parse::<i32>().unwrap());
                }
            };
        }
        qwq.sum()
    }
}
// @lc code=end
