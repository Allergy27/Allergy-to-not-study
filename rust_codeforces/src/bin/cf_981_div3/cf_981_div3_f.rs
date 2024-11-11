//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/10_24_f.rs
//@data      2024/10/25 01:48:21
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    // let t = 1;
    let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
const MOD: i64 = 1_000_000_007;
fn solve() {
    let (n, k) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<i64>().unwrap()));
    let fibo = || -> i64 {
        if k == 1 {
            return 1;
        }
        let (mut a1, mut a2, mut idx) = (1, 1, 3);
        while (a1 + a2) % k != 0 {
            a2 = (a2 + a1) % k;
            a1 = a2 - a1;
            idx += 1;
        }
        idx
    };
    let fib = fibo();
    println!("{}", (fib * (n % MOD)) % MOD)
}
