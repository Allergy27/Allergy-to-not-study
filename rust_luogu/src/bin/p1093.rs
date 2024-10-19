//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1093.rs
//@data      2024/01/17 23:47:58
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
struct Sc {
    id: usize,
    cn: usize,
    tot: usize,
}
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let n: usize = cin().parse().unwrap();
    let mut qwq: Vec<Sc> = vec![];
    for i in 1..=n {
        let (a, b, c) = cin()
            .split_whitespace()
            .fold((0, 0, 0), |x, y| (x.1, x.2, y.parse::<usize>().unwrap()));
        qwq.push(Sc {
            id: i,
            cn: a,
            tot: a + b + c,
        });
    }
    qwq.sort_unstable_by(|b, a| {
        if a.tot != b.tot {
            a.tot.cmp(&b.tot)
        } else if a.cn != b.cn {
            a.cn.cmp(&b.cn)
        } else {
            b.id.cmp(&a.id)
        }
    });
    qwq[0..5]
        .iter()
        .for_each(|x| println!("{} {}", x.id, x.tot));
}
