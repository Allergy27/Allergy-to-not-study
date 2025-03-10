//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/gcd.rs
//@data      2024/12/06 02:02:19
fn main() {
    // GCD
    let gcd = |mut a, mut b| loop {
        if b == 0 {
            break a;
        }
        (a, b) = (b, a % b)
    };

    // Test
    let (a, b) = (21i64, 3i64);
    println!("{}", gcd(a, b));
}
