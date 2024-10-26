//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/10_24_a.rs
//@data      2024/10/24 22:35:31
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_|solve());
}
fn solve() {
    let n =cin().parse::<usize>().unwrap();
    if n%2==1{
        println!("Kosuke")
    }else{
        println!("Sakurako")
    }
}