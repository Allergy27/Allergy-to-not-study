//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/10_24_c.rs
//@data      2024/10/24 23:08:45
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let n = cin().parse::<usize>().unwrap();
    let mut qwq = cin()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect::<Vec<i32>>();

    let (mut l, mut r) = ((n - 1) >> 1, (n - 1) >> 1);
    if n & 1 == 0 {
        r += 1;
    }
    for _ in (0..n).rev() {
        if l == 0 || r == n - 1 {
            break;
        }
        l -= 1;
        r += 1;
        if qwq[l] == qwq[l + 1] {
            qwq.swap(l, r);
        }
        if qwq[r] == qwq[r - 1] {
            qwq.swap(l, r);
        }
    }
    let mut ans = 0;
    for i in 1..n {
        if qwq[i] == qwq[i - 1] {
            ans += 1
        }
    }
    println!("{}", ans)
}
