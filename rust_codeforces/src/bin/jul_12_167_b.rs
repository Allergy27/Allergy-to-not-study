//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace codeforces/jul_12_167_a.rs
//@data      2024/07/12 20:55:11
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
    let a = cin();
    let b = cin();
    let mut b_set = std::collections::HashSet::<char>::new();
    b.chars().for_each(|x| {
        b_set.insert(x);
    });
    let b = b.chars().collect::<Vec<char>>();
    let mut check = vec![];
    for i in a.chars() {
        if let Some(&x) = b_set.get(&i) {
            check.push(x)
        }
    }
    let mut max = 0;
    let n = b.len();
    let m = check.len();
    for i in 0..n {
        let mut k = 0;
        let mut ka = 0;
        for j in 0..m {
            if i + k < n && i + ka < n {
                if check[j] == b[i + k] {
                    k += 1;
                } else {
                    max = k.max(max);
                    k = if check[j] == b[i] { 1 } else { 0 };
                }
                if check[j] == b[i + ka] {
                    ka += 1;
                }
            }
        }
        max = k.max(max).max(ka);
    }
    println!("{}", a.len() + b.len() - max);
    // aaaabaaaa abca
    // e t s t
    // t e s t e:(head_idx , tile_idx , max)
    //         t:(head_len , next_chr , max)
}
