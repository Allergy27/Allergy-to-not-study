//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/deu_171_div2_c.rs
//@data      2024/10/28 23:24:09
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
    let qwq = cin().chars().map(|x| x == '1').collect::<Vec<bool>>();
    let mut stk = std::collections::VecDeque::new();
    let mut ans = 0;
    for i in 0..n {
        if qwq[i as usize] {
            stk.push_back(i + 1);
        }
    }
    for i in (0..n).rev() {
        if !qwq[i as usize] {
            ans += i + 1;
            if !stk.is_empty() && stk.back().unwrap() > &i {
                stk.pop_back();
            }
        }
    }
    while !stk.is_empty() {
        let bk = stk.pop_back().unwrap();
        if stk.is_empty() {
            ans += bk;
            break;
        }
        let tp = stk.pop_front().unwrap();
        ans += tp;
    }
    println!("{}", ans);
}
