//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace codeforces/aug_30_966_c.rs
//@data      2024/08/30 17:38:37
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = cin().parse::<i32>().unwrap();
    let _ = (0..t).for_each(|_| solve());
}
fn solve() {
    let _ = cin().parse::<usize>().unwrap();
    let mut check_out = std::collections::HashMap::<i32, usize>::new();
    let check = cin()
        .split_whitespace()
        .enumerate()
        .map(|(i, s)| {
            if let Some(&k) = check_out.get(&s.parse::<i32>().unwrap()) {
                k
            } else {
                check_out.insert(s.parse::<i32>().unwrap(), i);
                i
            }
        })
        .collect::<Vec<usize>>();
    let qb = || {
        let mut ob_check = vec![27; 26];
        cin()
            .chars()
            .enumerate()
            .map(|(i, s)| {
                if ob_check[s as usize - 97] != 27 {
                    ob_check[s as usize - 97]
                } else {
                    ob_check[s as usize - 97] = i;
                    i
                }
            })
            .collect::<Vec<usize>>()
    };
    let p = cin().parse::<usize>().unwrap();
    for _ in 0..p {
        println!("{}", if qb() == check { "Yes" } else { "No" })
    }
}
