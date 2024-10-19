/*
 * @lc app=leetcode.cn id=3106 lang=rust
 *
 * [3106] 满足距离约束且字典序最小的字符串
 */

// @lc code=start
impl Solution {
    pub fn get_smallest_string(s: String, mut k: i32) -> String {
        s.chars()
            .scan('0', |ans, x| {
                if k == 0 {
                    return Some(x);
                }
                let dis = (x as u8 - b'a').min(b'z' - x as u8 + 1) as i32;
                if dis > k {
                    let res = Some((x as u8 - k as u8) as char);
                    k = 0;
                    return res;
                }
                k -= dis;
                Some('a')
            })
            .collect()
    }
}
// @lc code=end
