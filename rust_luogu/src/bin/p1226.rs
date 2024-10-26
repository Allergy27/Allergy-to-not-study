//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1226.rs
//@data      2024/10/24 11:53:59
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}

fn qpow<T>(mut a: T, mut b: T, m: T) -> T
where
    T: Copy
        + From<bool>
        + std::ops::Rem<Output = T>
        + std::ops::Mul<Output = T>
        + std::ops::ShrAssign
        + std::cmp::PartialOrd
        + std::ops::BitAnd<Output = T>
        + std::ops::Sub<Output = T>,
{
    let one = true.into();
    let zero = false.into();
    let mut ans = one;
    while b > zero {
        if (b & one) == one {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b >>= one;
    }
    ans
}

fn solve() {
    let (a, b, c) = cin()
        .split_whitespace()
        .fold((0, 0, 0), |x, y| (x.1, x.2, y.parse::<usize>().unwrap()));
    println!("{}^{} mod {}={}", a, b, c, qpow(a, b, c));
}
