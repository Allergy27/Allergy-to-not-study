//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p4343.rs
//@data      2024/10/24 11:31:38
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (n, k) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    let mut qwq = vec![0i64; n];
    for x in &mut qwq {
        *x = cin().parse().unwrap();
    }
    let check = |v: i64| -> i64 {
        let mut cnt = 0;
        let mut ans = 0;
        for &x in &qwq {
            cnt += x;
            if cnt >= v {
                cnt = 0;
                ans += 1;
            } else if cnt < 0 {
                cnt = 0;
            }
        }
        ans
    };
    let binary = |k: i64| -> i64 {
        let (mut l, mut r) = (0, 1e18 as i64);
        while l < r {
            let mid = (l + r) >> 1;
            if check(mid) > k {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        l
    };
    let bn = binary(k as i64);
    let bn = if bn == 0 { 1 } else { bn };
    let bm = binary(k as i64 - 1) - 1;
    if check(bn) != k as i64 {
        println!("-1");
        return;
    }
    println!("{} {}", bn, bm);
}
