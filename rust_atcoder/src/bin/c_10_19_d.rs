//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace rust_atcoder/c_10_19_d.rs
//@data      2024/10/19 20:51:54
use proconio::input;

fn main() {
    let t = 1; //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    input! {
        n:usize,
        m:usize,
        edges:[(usize,usize);m],
    }
    let mut graph = vec![vec![]; n + 1];
    for (u, v) in edges {
        graph[u].push(v);
        graph[v].push(u);
    }
    let bfs = || {
        let mut q = std::collections::VecDeque::new();
        q.push_back((1, 1));
        while !q.is_empty() {
            let (v, t) = q.pop_front().unwrap();
            for &u in &graph[v] {
                //孩子
                if u == 1 && v != 1 {
                    return t + 1;
                }
                q.push_back((u, t + 1));
            }
        }
        -1
    };
    println!("{}", bfs());
}
