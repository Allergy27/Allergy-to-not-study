//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p5739.rs
//@data      2024/10/27 19:58:43
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
    let n = cin().parse::<usize>().unwrap();
    println!("{}", multi(n));
}

fn multi(n: usize) -> usize {
    if n == 1 {
        1
    } else {
        n * multi(n - 1)
    }
}
