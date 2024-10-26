//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p7869.rs
//@data      2024/10/23 20:26:46
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
    let s = cin();
    println!(
        "{}",
        if s.contains("\\r\\n") {
            "windows"
        } else if s.contains("\\r") {
            "mac"
        } else {
            "linux"
        }
    )
}
