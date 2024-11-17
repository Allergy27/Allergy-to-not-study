//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1319.rs
//@data      2023/12/20 17:27:53
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
    let mut qwq = cin();
    let n = qwq.len();
    (1..n).for_each(|_| qwq.push_str(&cin()));
    let mut ans = vec![n];
    let mut check = (0, 0);
    qwq.chars().enumerate().for_each(|x| {
        if x.1 as i32 ^ 48 != check.1 {
            ans.push(check.0);
            check.0 = 1;
            check.1 = (check.1 + 1) % 2;
        }else {
            check.0+=1;
        }
    });
    ans.push(check.0);
    ans.iter().for_each(|x|print!("{} ",x));
}
