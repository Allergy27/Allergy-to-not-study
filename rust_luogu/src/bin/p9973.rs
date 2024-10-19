//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p9973.rs
//@data      2023/12/20 11:57:50
fn input() -> String {
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
    if input()
        .chars()
        .zip(String::from("You are right, but ").chars())
        .skip_while(|x| x.0 == x.1)
        .eq(None)
    {
        println!("AI");
    } else {
        println!("Human")
    }
}
