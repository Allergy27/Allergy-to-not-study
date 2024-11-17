use std::f32::consts::E;

//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1423.rs
//@data      2023/12/13 21:27:40
fn main() {
    let t=1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_|solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let x:f32 = input.trim().parse().unwrap();
    println!("{:.0}",((1.0-x/100.0).log(E)/0.98_f32.log(E)).ceil())
}