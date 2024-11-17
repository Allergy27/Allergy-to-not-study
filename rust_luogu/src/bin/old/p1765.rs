//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1765.rs
//@data      2023/12/22 18:33:30
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input[..input.len() - 2].to_string()
}
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let qvq = [
        1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4,
    ];
    println!(
        "{}",
        cin().chars().fold(0, |s, x: char| {
            s + if x.is_ascii_lowercase() {
                qvq[x as usize]
            } else {
                1
            }
        })
    )
}
