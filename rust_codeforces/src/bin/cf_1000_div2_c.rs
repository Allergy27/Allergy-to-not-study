//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_1000_div2_c.rs
//@data      2025/01/22 20:49:09

fn main() {
    // let t = 1;
    let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let n = cin!(usize);
    let mut qwq = vec![vec![]; n];
    let mut deg = vec![0; n];
    for _ in 1..n {
        let (u, v) = cin!(usize, usize);
        qwq[u - 1].push(v - 1);
        qwq[v - 1].push(u - 1);
        deg[u - 1] += 1;
        deg[v - 1] += 1;
    }
    let mut nodes = Vec::with_capacity(n);
    (0..n).for_each(|i| nodes.push((deg[i], i)));
    nodes.sort_by(|a, b| b.0.cmp(&a.0));
    let mut rank = vec![0; n];
    (0..n).for_each(|i| rank[nodes[i].1] = i);
    let mut ans = 0;
    for v in 0..n {
        let x = deg[v];
        let mut s = std::collections::HashSet::new();
        s.insert(v);
        for nx in qwq[v].iter() {
            s.insert(*nx);
        }
        let mut res1 = 0;
        for nd in nodes.iter() {
            let tmp = nd.1;
            if !s.contains(&tmp) {
                res1 = deg[tmp];
                break;
            }
        }
        let mut res2 = 0;
        for nx in qwq[v].iter() {
            res2 = res2.max(deg[*nx] - 1);
        }
        ans = ans.max(res2.max(res1) + if x > 0 { x - 1 } else { 0 });
    }
    println!("{}", ans);
}

#[macro_export]
macro_rules! cin {
    ()=>{{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().to_string()
    }};
    ([char]) => {{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().chars().collect::<Vec<char>>()
    }};
    ([u8]) =>{{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().bytes().collect::<Vec<u8>>()
    }};
    ([$type:ty;$n:expr]) => {{
        let mut input = String::new();
        let mut s = loop{
            input.clear();
            std::io::stdin().read_line(&mut input).unwrap();
            let s = input.trim();
            if !s.is_empty() {
                break s.split_whitespace();
            }
        };
        let mut arr = Vec::with_capacity($n as usize);
        for _ in 0..$n {
            arr.push((s.next().unwrap()).parse::<$type>().unwrap());
        }
        arr
    }};
    ($type:ty) => {{
        let mut input = String::new();
        let mut s = loop{
            input.clear();
            std::io::stdin().read_line(&mut input).unwrap();
            let s = input.trim();
            if !s.is_empty() {
                break s.split_whitespace();
            }
        };
        (s.next().unwrap()).parse::<$type>().unwrap()
    }};
    ($($type:ty),*) => {{
        let mut input = String::new();
        let mut s = loop{
            input.clear();
            std::io::stdin().read_line(&mut input).unwrap();
            let s = input.trim();
            if !s.is_empty() {
                break s.split_whitespace();
            }
        };
        ($(s.next().unwrap().parse::<$type>().unwrap()),*)
    }}
}
