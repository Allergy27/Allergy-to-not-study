//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1553.rs
//@data      2023/12/22 20:53:30
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    let _ = (0..t).for_each(|_| solve());
}
fn solve() {
    let ans = cin()
        .chars()
        .fold((String::new(), String::new(), String::new()), |x, c| {
            let y = c.to_string();
            if x.1.is_empty() {
                if '0' <= c && c <= '9' {
                    (y + &x.0, x.1, x.2)
                } else {
                    (x.0, x.1 + &y, x.2)
                }
            } else {
                (x.0, x.1, y + &x.2)
            }
        });
    if ans.1 != "." {
        println!("{}{}{}", del(ans.0), ans.1, del(ans.2))
    } else {
        println!(
            "{}{}{}",
            del(ans.0),
            ans.1,
            del(ans.2.chars().rev().collect())
                .chars()
                .rev()
                .collect::<String>()
        )
    }
}
fn del(s: String) -> String {
    s.chars().skip_while(|x| s.len() > 1 && x == &'0').collect()
}
