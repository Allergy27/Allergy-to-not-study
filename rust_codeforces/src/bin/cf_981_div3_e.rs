//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/10_24_e.rs
//@data      2024/10/24 23:37:40
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    // let t = cin().parse::<i32>().unwrap();
    let t = 1;
    (0..t).for_each(|_| solve());
}

fn solve() {
    let n = cin().parse::<usize>().unwrap();
    let qwq =
        cin().split_whitespace().map(|s| s.parse::<usize>().unwrap() - 1).collect::<Vec<_>>();
    let mut qaq: Vec<usize> = (0..n).collect();
    for _ in 0..1000 {
        for i in 0..n {
            qaq[i] = qwq[qaq[i]];
        }
    }
    let st = std::collections::HashSet::<usize>::from_iter(qaq);
    println!("{}", st.len());
}
