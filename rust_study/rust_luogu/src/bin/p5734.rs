//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p5734.rs
//@data      2023/12/20 21:15:54
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
    let q: usize = cin().parse().unwrap();
    let mut ans = cin();
    (0..q).for_each(|_| {
        let qwq = cin();
        let qwq = qwq.split_whitespace().collect::<Vec<&str>>();
        if qwq[0] == "1" {
            ans.push_str(qwq[1]);
            println!("{}", ans);
        } else if qwq[0] == "2" {
            let a = qwq[1].parse::<usize>().unwrap();
            ans = ans[a..a + qwq[2].parse::<usize>().unwrap()].to_string();
            println!("{}", ans);
        } else if qwq[0] == "3" {
            let a = qwq[1].parse::<usize>().unwrap();
            ans = ans[..a]
                .chars()
                .chain(qwq[2].chars())
                .chain(ans[a..].chars())
                .collect::<String>();
            println!("{}", ans);
        } else if qwq[0] == "4" {
            let res = (0..ans.len() - qwq[1].len() + 1).fold(-1, |x, y| {
                if x == -1 && &ans[y..y + qwq[1].len()] == qwq[1] {
                    y as i32
                } else {
                    x
                }
            });
            println!("{}", res);
        }
    })
}
