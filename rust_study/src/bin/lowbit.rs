//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace study/lowbit.rs
//@data      2024/04/15 19:24:03
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let lowbit_fn = |x: i32| x & -x;
    println!("{}", lowbit_fn(cin().parse::<i32>().unwrap()))
}