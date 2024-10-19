//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1427.rs
//@data      2023/12/17 21:39:57
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input
        .split_whitespace()
        .rev()
        .skip(1)
        .for_each(|x| print!("{} ", x));
}
