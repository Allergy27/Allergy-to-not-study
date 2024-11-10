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
    let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}

fn solve() {
    let n = cin().parse::<usize>().unwrap();
    let qwq = cin()
        .split_whitespace()
        .map(|s| s.parse::<usize>().unwrap() - 1)
        .collect::<Vec<_>>();
    let mut qaq = vec![true; n]; //true表示还能连环
    let mut ans = 0;
    for i in 0..n {
        qaq[i] = false; //现在连上了
        let mut cnt = 1;
        let mut tmp = qwq[i];
        //下一个还能连环就去访问
        while qaq[tmp] {
            qaq[tmp] = false;
            tmp = qwq[tmp];
            cnt += 1;
        }
        ans += (cnt - 1) / 2;
    }
    println!("{}", ans);
}
