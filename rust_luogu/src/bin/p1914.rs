//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1914.rs
//@data      2023/12/20 19:27:48
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t=1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    let _ = (0..t).for_each(|_|solve());
}
fn solve() {
    let n:u8 = cin().parse().unwrap();
    println!("{}",cin().chars().map(|x|((((x as u8)-97)+ n)%26+97) as char).collect::<String>());
}