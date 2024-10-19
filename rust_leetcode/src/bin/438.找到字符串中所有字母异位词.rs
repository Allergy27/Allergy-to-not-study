/*
 * @lc app=leetcode.cn id=438 lang=rust
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
impl Solution {
    pub fn find_anagrams(s: String, p: String) -> Vec<i32> {
        let s = s.as_bytes();
        let p = p.as_bytes();
        let mut ans = Vec::new();
        let (mut st, mut pt) = ([0; 26], [0; 26]);
        for &i in p.iter() {
            pt[i as usize - 97] += 1;
        }
        let mut l = 0;
        for r in 0..s.len() {
            st[s[r] as usize - 97] += 1;
            if r >= p.len() - 1 {
                if st == pt {
                    ans.push(l as i32);
                }
                st[s[l] as usize - 97] -= 1;
                l += 1;
            }
        }
        ans
    }
}
// @lc code=end
