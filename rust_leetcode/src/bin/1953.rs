//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace leetcode/1953.rs
//@data      2023/12/23 15:14:06
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let word = String::from("igigee");
    let k = 2;
    //--------------------------------
    let word = word.chars().collect::<Vec<char>>();
    let n = word.len();
    let ans = (1..=n)
        .fold((0, 0, word[0]), |x, i| {
            if i < n && -2 <= word[i] as i32 - x.2 as i32 && word[i] as i32 - x.2 as i32 <= 2 {
                (x.0, x.1, word[i])
            } else {
                (x.0 + find(word[x.1..i].to_vec(), k), i, word[i])
            }
        })
        .0;
    println!("{}", ans);
}
fn find(s: Vec<char>, k: i32) -> i32 {
    (1..=26)
        .filter(|&t| t * k < s.len() as i32)
        .fold(0, |x, m| {
            let mut qwq = [0; 26];
            (0..m * k - 1).for_each(|u| qwq[s[u as usize] as usize - 97] += 1);
            x + (0..s.len() - (m * k) as usize).fold(0, |u, p| {
                qwq[s[p + (m * k - 1) as usize] as usize - 97] += 1;
                u + if (0..26).any(|b| qwq[b] != 0 && qwq[b] != k) {
                    qwq[s[p] as usize - 97] -= 1;
                    0
                } else {
                    qwq[s[p] as usize - 97] -= 1;
                    1
                }
            })
        })
}
