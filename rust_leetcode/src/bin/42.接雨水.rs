/*
 * @lc app=leetcode.cn id=42 lang=rust
 *
 * [42] 接雨水
 */

// @lc code=start
impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let mut qwq: Vec<usize> = Vec::new(); //单调栈
        let mut ans = 0;
        for (i, &x) in height.iter().enumerate() {
            while !qwq.is_empty() && x > height[qwq[qwq.len() - 1]] {
                let low = height[qwq.pop().unwrap()];
                if qwq.is_empty() {
                    break;
                }
                let left=qwq[qwq.len()-1];
                let now=height[left].min(x) - low;
                ans += now *((i-left-1) as i32);
            }
            qwq.push(i);
        }
        ans
    }
}
// @lc code=end
