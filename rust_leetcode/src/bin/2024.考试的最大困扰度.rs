/*
 * @lc app=leetcode.cn id=2024 lang=rust
 *
 * [2024] 考试的最大困扰度
 */

// @lc code=start
impl Solution {
    pub fn max_consecutive_answers(answer_key: String, k: i32) -> i32 {
        let key: Vec<usize> = answer_key
            .as_bytes()
            .iter()
            .map(|&x| (x >> 1 & 1) as usize)
            .collect();
        let n = key.len();
        let mut qwq = vec![0, 0];
        let mut start = 0;
        let mut ans = 0;
        for end in 0..n {
            qwq[key[end]] += 1;
            while qwq[0] >= k && qwq[1] >= k {
                qwq[key[start]] -= 1;
                start += 1;
            }
            ans = ans.max(end - start);
        }
        ans
    }
}
// @lc code=end
