//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace study/class_tower.rs
//@data      2024/06/25 14:38:45
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    println!("Please enter the 'n' to describe the height of tower:");
    let n = cin().parse::<usize>().unwrap();
    //读输入
    println!("Please enter the number of tower in one line:");
    let mut qwq = cin()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect::<Vec<i32>>();
    for i in (1..n).rev() {
        let inital_value = i * (i + 1) / 2 - 1;
        for j in 0..i {
            qwq[inital_value - j] += qwq[inital_value - j + i].max(qwq[inital_value - j + i + 1])
        }
    }
    println!("{}", qwq[0])
}
