//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1029.rs
//@data      2024/10/28 19:10:16
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let gcd = |x: i64, y: i64| {
        let mut op = (x, y);
        while op.1 != 0 {
            op = (op.1, op.0 % op.1);
        }
        op.0
    };
    let (n, m) = cin().split_whitespace().fold((0, 0), |x, y| (x.1, y.parse::<i64>().unwrap()));
    let num = n * m;
    let mut ans = 0;
    for i in 1..=m {
        if i * i > num {
            break;
        }
        if i * i == num && gcd(num / i, i) == n {
            ans += 1
        } else if num % i == 0 && gcd(num / i, i) == n {
            ans += 2;
        }
    }
    println!("{}", ans);
}
