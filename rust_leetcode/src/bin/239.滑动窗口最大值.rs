/*
 * @lc app=leetcode.cn id=239 lang=rust
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
impl Solution {
    pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut qwq = std::collections::VecDeque::new();
        let mut ans = Vec::new();
        for (i, x) in nums.into_iter().enumerate() {
            //先维护单调队列
            while let Some(&(_, y)) = qwq.back() {
                if y >= x {
                    break;
                }
                qwq.pop_back();
            }
            qwq.push_back((i, x));
            if i as i32 >= k - 1 {
                while let Some(&(j, _)) = qwq.front() {
                    if j + k as usize > i {
                        break;
                    }
                    qwq.pop_front();
                }
                ans.push(qwq.front().unwrap().1)
            }
        }
        ans
    }
}
// @lc code=end
