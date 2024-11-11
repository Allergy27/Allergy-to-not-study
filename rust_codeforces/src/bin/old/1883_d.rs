//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/1883_d.rs
//@data      2024/10/25 13:42:07
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    // let a = [1, 1, 1, 2, 23, 3, 4, 4, 1, 1];
    // let b = std::collections::BTreeSet::from_iter(a);
    // println!("{:?}", b);
    let n = cin().parse::<usize>().unwrap();
    let mut qwq_l = std::collections::BTreeMap::new();
    let mut qwq_r = std::collections::BTreeMap::new();
    for _ in 0..n {
        let (a, b, c) = cin()
            .split_whitespace()
            .fold((String::new(), String::new(), String::new()), |x, y| {
                (x.1, x.2, y.to_string())
            });
        let (op, l, r) = (
            a.parse::<char>().unwrap(),
            b.parse::<usize>().unwrap(),
            c.parse::<usize>().unwrap(),
        );
        if op == '+' {
            qwq_l.insert(l, qwq_l.get(&l).unwrap_or(&0) + 1);
            qwq_r.insert(r, qwq_r.get(&r).unwrap_or(&0) + 1);
        } else {
            if let Some(v) = qwq_l.get_mut(&l) {
                *v -= 1;
                if *v == 0 {
                    qwq_l.remove(&l);
                }
            }
            if let Some(v) = qwq_r.get_mut(&r) {
                *v -= 1;
                if *v == 0 {
                    qwq_r.remove(&r);
                }
            }
        }
        // println!(
        //     "{:?} {:?}",
        //     qwq_l.iter().next_back().unwrap(),
        //     qwq_r.iter().next().unwrap()
        // );
        println!(
            "{}",
            if qwq_l.len() > 1
                && qwq_l.iter().next_back().unwrap().0 > qwq_r.iter().next().unwrap().0
            {
                "YES"
            } else {
                "NO"
            }
        );
    }
}
