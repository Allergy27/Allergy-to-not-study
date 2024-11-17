//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p5733.rs
//@data      2023/12/20 19:11:08
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    println!(
        "{}",
        cin()
            .chars()
            .scan("", |_, x: char| if x.is_ascii_lowercase() {
                Some((32 ^ (x as u8)) as char)
            } else {
                Some(x)
            })
            .collect::<String>()
    );
}
