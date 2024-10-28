//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_global_round_d.rs
//@data      2024/10/28 00:14:47
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
fn solve() {
    let n = cin().parse::<usize>().unwrap();
    let qwq = cin()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect::<Vec<i64>>();
    const MOD: i64 = 1e9 as i64 + 7;
    let qpow = |b: i64| {
        if b == 0 {
            return 1;
        }
        let mut x = 2;
        let mut b = b - 1;
        let mut ans = x;
        while b != 0 {
            if b & 1 != 0 {
                ans = ans * x % MOD;
            }
            x = x * x % MOD;
            b >>= 1;
        }
        ans
    };
    let lowbit = |x: i64| {
        let mut ans = 0;
        let mut pik = x;
        while pik & 1 == 0 {
            ans += 1;
            pik >>= 1;
        }
        ans
    };

    let mut stk = vec![(0, 0)]; //底是二，x2数是0
    let mut ans = 0;
    for &num in &qwq {
        // println!("?{} {}", tmp, num);
        ans += num;
        let mut tmp = (num >> lowbit(num), lowbit(num));
        while !stk.is_empty() && stk.last().unwrap().0 < (tmp.0 * qpow(tmp.1)) {
            let (x, y) = stk.pop().unwrap();
            tmp = (tmp.0, tmp.1 + y);
            ans = (ans - x * qpow(y - 1) + MOD) % MOD;
            ans = (ans + tmp.0 * qpow(tmp.1 - 1)) % MOD;
        }
        if stk.is_empty() {
            stk.push(tmp);
        }
        println!("{}", ans)
        //发生交接
    }
    println!();
}
