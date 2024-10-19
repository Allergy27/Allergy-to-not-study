//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p2440.rs
//@data      2024/01/19 13:43:05
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (a, x) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<u32>().unwrap()));
    let mut qwq = Vec::new();
    (0..a).for_each(|_| qwq.push(cin().parse::<u32>().unwrap()));
    let (mut l, mut r) = (0, 100_000_001u32);
    let f = |ans: u32| qwq.iter().fold(0, |p, &q| p + q / ans) >= x;
    while l + 1 < r {
        let mid = (l + r) / 2;
        if f(mid) {
            l = mid;
        } else {
            r = mid;
        }
    }
    println!("{}", l);
}
