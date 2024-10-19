/*
 * @lc app=leetcode.cn id=3174 lang=rust
 *
 * [3174] 清除数字
 */

// @lc code=start

pub fn min_starting_index(s: String, pattern: String) -> i32 {
    let s = s
        .chars()
        .map(|c| (c as u8 - b'a') as usize)
        .collect::<Vec<_>>();
    let p = pattern
        .chars()
        .map(|c| (c as u8 - b'a') as usize)
        .collect::<Vec<_>>();

    let d = p.iter().chain(s.iter()).copied().collect::<Vec<_>>();
    let dz = z_algorithm(&d);
    let r = p
        .iter()
        .rev()
        .chain(s.iter().rev())
        .copied()
        .collect::<Vec<_>>();
    let rz = z_algorithm(&r);
    for i in 0..=s.len() - p.len() {
        if dz[i + p.len()] + rz[p.len() + s.len() - p.len() - i] >= p.len() - 1 {
            return i as i32;
        }
    }
    -1
}

fn z_algorithm(s: &[usize]) -> Vec<usize> {
    let mut res = Vec::with_capacity(s.len());
    res.push(0);
    let mut l = 0;
    let mut r = 0;
    for i in 1..s.len() {
        if i <= r {
            let cur = (r - i + 1).min(res[i - l]);
            res.push(cur);
        } else {
            res.push(0);
        }
        while i + res[i] < s.len() && s[res[i]] == s[i + res[i]] {
            res[i] += 1;
        }
        if i + res[i] - 1 > r {
            l = i;
            r = i + res[i] - 1;
        }
    }
    res
}

fn main() {
    println!(
        "{}",
        min_starting_index("abcdefg".to_string(), "bcdffg".to_string())
    );
}
// @lc code=end
