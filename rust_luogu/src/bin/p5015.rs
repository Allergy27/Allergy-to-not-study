//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p5015.rs
//@data      2023/12/20 21:10:40
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    let _ = (0..t).for_each(|_| solve());
}
fn solve() {
    println!(
        "{}",
        cin()
            .chars()
            .filter(|&x| x != ' ')
            .collect::<String>()
            .len()
    );
}
