//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1309.rs
//@data      2024/10/24 15:13:26
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (n, r, q) =
        cin().split_whitespace().fold((0, 0, 0), |x, y| (x.1, x.2, y.parse::<usize>().unwrap()));

    let socre = cin().split_whitespace().map(|s| s.parse().unwrap()).collect::<Vec<i32>>();
    let strenth = cin().split_whitespace().map(|s| s.parse().unwrap()).collect::<Vec<i32>>();
    let mut qwq = socre.into_iter().zip(strenth).zip(1..=2 * n).collect::<Vec<_>>();

    let cpr = |a: &((i32, i32), usize), b: &((i32, i32), usize)| {
        if a.0 .0 == b.0 .0 {
            return a.1.cmp(&b.1);
        }
        b.0 .0.cmp(&a.0 .0)
    };
    qwq.sort_unstable_by(&cpr);
    for _ in 0..r {
        for i in 0..n {
            if qwq[i * 2].0 .1 > qwq[i * 2 + 1].0 .1 {
                qwq[i * 2].0 .0 += 1;
            } else {
                qwq[i * 2 + 1].0 .0 += 1;
            }
        }
        qwq.sort_unstable_by(&cpr);
    }
    // qwq.iter().for_each(|x| println!("{:?}", x));
    println!("{}", qwq[q - 1].1)
}
