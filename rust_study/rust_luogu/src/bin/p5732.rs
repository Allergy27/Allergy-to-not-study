//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p5732.rs
//@data      2023/12/20 15:54:32
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t=1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_|solve());
}
fn solve() {
    let n:usize = cin().parse().unwrap();
    (0..n).for_each(|m|{
        (0..=m).for_each(|x|print!("{} ",yang(m)/yang(m-x)/yang(x)));
        println!()
    })
}
fn yang(k:usize)->usize{
    (1..=k).product::<usize>()
}