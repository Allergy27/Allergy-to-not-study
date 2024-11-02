//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/test.rs
//@data      2024/10/29 10:04:26
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let a = [1, 3, 5, 7, 9];
    println!("{}", a.partition_point(|&x| x < 5));
}
