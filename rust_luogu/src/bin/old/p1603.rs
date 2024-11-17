//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1603.rs
//@data      2023/12/22 21:14:27
use std::collections::HashMap;
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
    let k = vec![
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "a",
        "both",
        "another",
        "first",
        "second",
        "third",
    ]; //key
    let v = vec![
        0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 00, 21, 44, 69, 96, 25, 56, 89, 24, 61, 0, 1, 4, 1, 1,
        4, 9,
    ]; //value
    let check = k.iter().zip(v).collect::<HashMap<_, _>>();
    let mut qwq = cin()
        .split_whitespace()
        .filter_map(|x| if k.contains(&x) { check.get(&x) } else { None })
        .map(|x| format!("{x}"))
        .collect::<Vec<_>>();
    qwq.sort_by(|a, b| a.partial_cmp(b).unwrap());
    qwq.iter()
        .skip_while(|m| m == &&"0".to_string())
        .collect::<Vec<_>>()
        .iter()
        .rev()
        .for_each(|x| print!("{x}"));
}
