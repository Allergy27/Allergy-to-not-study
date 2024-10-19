//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\1a.rs
//@data      2023/12/05 19:09:27
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    for _ in 0..t {
        solve()
    }
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut input = input.trim().split_whitespace();
    let (a, b, c): (f64, f64, f64) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );

    println!("{}", (a / c).ceil() as i128 * (b / c).ceil() as i128);
}
