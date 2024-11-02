//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/edu_171_div2_b.rs
//@data      2024/10/28 22:58:03
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    // let t = 1;
    let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let n = cin().parse::<i64>().unwrap();
    let qwq = cin()
        .split_whitespace()
        .map(|s| s.parse::<i64>().unwrap())
        .collect::<Vec<_>>();

    let mut ans = i64::MAX;
    if n == 1 {
        ans = 1;
    } else if n % 2 == 0 {
        let mut arr = vec![];
        for i in (1..n).step_by(2) {
            arr.push(qwq[i as usize] - qwq[i as usize - 1]);
        }
        ans = ans.min(*arr.iter().max().unwrap())
    } else {
        for i in 0..n {
            let mut j = 0;
            let mut arr = vec![];
            while j + 1 < n {
                if j == i {
                    j += 1
                }
                arr.push(qwq[1 + j as usize] - qwq[j as usize]);
                j += 2
            }
            ans = ans.min(*arr.iter().max().unwrap())
        }
    }

    println!("{}", ans);
}
