//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1957.rs
//@data      2023/12/20 20:30:48
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
    let n: usize = cin().parse().unwrap();
    let mut ch = '0';
    let ch_all = ['+', '-', '*'];
    (0..n).for_each(|_| {
        let input = cin();
        let qwq = input.split_whitespace().collect::<Vec<&str>>();
        if qwq.len() == 3 {
            ch = ch_all[(qwq[0].chars().next().unwrap() as u8 - 97) as usize];
        }
        let qwq = if qwq.len() == 3 {
            qwq.iter()
                .skip(1)
                .map(|&x| x.parse::<i32>().unwrap())
                .collect::<Vec<i32>>()
        } else {
            qwq.iter()
                .map(|&x| x.parse::<i32>().unwrap())
                .collect::<Vec<i32>>()
        };

        let res = match ch {
            '+' => qwq[0] + qwq[1],
            '-' => qwq[0] - qwq[1],
            '*' => qwq[0] * qwq[1],
            _ => unreachable!(),
        };
        let ans = format!("{}{}{}={}", qwq[0], ch, qwq[1], res);
        println!("{}\n{}", ans, ans.len());
    });
}
