//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p2669_no_table.rs
//@data      2023/12/13 17:22:19
fn main() {
    let t=1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    let _ = (0..t).for_each(|_|solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let d:f64 = input.trim().parse().unwrap();
    //下面是处理
    let n: f64=((((1+(d as i32)<<3)as f64).sqrt()-1.0)/2.0).floor();
    println!("{:.0}",n*(d-(n+1.0)*(n+2.0)/6.0)+d);
}