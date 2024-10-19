/*
 * @lc app=leetcode.cn id=1944 lang=rust
 *
 * [1944] 队列中可以看到的人数
 */

// @lc code=start
impl Solution {
    pub fn can_see_persons_count(heights: Vec<i32>) -> Vec<i32> {
        let mut st = Vec::new();
        heights
            .iter()
            .enumerate()
            .rev()
            .map(|(i, &h)| {
                let mut ans = 0;
                while let Some(&x) = st.last() {
                    ans += 1;
                    if x > h {
                        break;
                    }
                    st.pop();
                }
                st.push(h);
                ans
            })
            .rev()
            .collect()
    }
}
// @lc code=end
