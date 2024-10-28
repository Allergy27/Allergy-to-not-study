//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/10_26_c.rs
//@data      2024/10/26 20:18:22
use proconio::input;

fn main() {
    let t = 1;
    //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    input! {
        n:i64,
        m:i64,
        qwq: [(i64, i64); m],
    }
    let mut st = std::collections::HashSet::new();
    let move_list = [
        (0, 0),
        (2, 1),
        (1, 2),
        (-1, 2),
        (-2, 1),
        (-2, -1),
        (-1, -2),
        (1, -2),
        (2, -1),
    ];
    for (x, y) in qwq {
        for (dx, dy) in move_list {
            let mx = x + dx;
            let my = y + dy;
            if mx < 1 || mx > n {
                continue;
            }
            if my < 1 || my > n {
                continue;
            }
            st.insert((mx, my));
        }
    }
    println!("{}", n * n - (st.len() as i64))
}
