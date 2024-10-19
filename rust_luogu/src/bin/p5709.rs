//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p5709.rs
//@data      2023/12/04 13:20:01
//
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    for _ in 0..t {
        solve();
    }
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut input = input.split_whitespace();
    let (m, t, s): (i32, i32, i32) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );
    if t == 0 {
        println!("{}", 0);
        return;
    }
    if s / t >= m {
        println!("{}", 0);
        return;
    }
    println!("{}", m - (s as f64 / t as f64).ceil() as i32);
}
