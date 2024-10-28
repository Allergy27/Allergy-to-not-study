//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p5737.rs
//@data      2024/10/27 19:56:25
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
    let check = |x: usize| x % 4 == 0 && x % 100 != 0 || x % 400 == 0;
    let (a, b) = cin().split_whitespace().fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    let mut qwq = vec![];
    for i in a..=b {
        if check(i) {
            qwq.push(i);
        }
    }
    println!("{}", qwq.len());
    qwq.iter().for_each(|x| print!("{} ", x));
}
