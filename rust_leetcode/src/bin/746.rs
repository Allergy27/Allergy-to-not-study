//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace leetcode/746.rs
//@data      2023/12/17 10:51:39
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let cost = [10, 15];
    let ans = cost
        .iter()
        .fold((0, 0), |x, &y| (x.1.min(x.0 + y), x.0 + y));
    println!("{}", ans.0);
}
