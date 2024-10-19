//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1720.rs
//@data      2023/12/15 19:44:32
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    let _ = (0..t).for_each(|_| solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: i128 = (0..input.trim().parse().unwrap())
        .fold((0, 1), |x, _| (x.1, x.0 + x.1))
        .0;
    println!("{}.00", n);
}
