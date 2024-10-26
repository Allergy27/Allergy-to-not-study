//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/10_24_d.rs
//@data      2024/10/25 00:24:07
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let n = cin().parse::<usize>().unwrap();
    let qwq = cin()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect::<Vec<i32>>();
    let mut qaq = vec![0; n + 1];
    qaq[1] = qwq[0];
    for i in 1..n {
        qaq[i + 1] = qaq[i] + qwq[i];
    }
    let mut st = std::collections::HashSet::new();
    let mut ans = 0;
    for i in qaq.iter() {
        if st.contains(&i) {
            ans += 1;
            st.clear();
        };
        st.insert(i);
    }
    println!("{}", ans);
}
