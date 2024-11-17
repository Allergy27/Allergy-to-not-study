//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p5277.rs
//@data      2023/12/13 20:41:31
fn main() {
    let t=1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_|solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n:i32 = input.trim().parse().unwrap();
    let ans=(1..=n).sum::<i32>();
    println!("{}",ans);
}