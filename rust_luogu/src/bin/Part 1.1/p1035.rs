use std::io;
fn main() {
    let mut s_n: f64 = 0.0;
    let mut k: f64 = 0.0;
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("hehe");
    let n: f64 = input.trim().parse().expect("haha");
    while s_n <= n {
        k += 1.0;
        s_n += 1.0 / k;
    }
    println!("{:.0}", k);
}
