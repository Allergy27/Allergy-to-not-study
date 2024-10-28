//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_global_round_c.rs
//@data      2024/10/27 23:22:24
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
    let n = cin().parse::<usize>().unwrap();
    let mut qwq = (1..=n).collect::<Vec<usize>>();
    let bit_count = |x: usize| {
        let mut tmp = x;
        let mut ans = 0;
        while tmp != 0 {
            ans += 1;
            tmp >>= 1;
        }
        ans
    };
    qwq.sort_by(|&a, &b| {
        let q = bit_count(a | b);
        a.cmp(&q).then(b.cmp(&q))
    });


    let ans = qwq
        .iter()
        .enumerate()
        .fold(0, |ans, (i, x)| if i & 1 == 0 { ans & x } else { ans | x });
    println!("{}", ans);
    qwq.iter().for_each(|x| print!("{} ", x));
    println!()
}
