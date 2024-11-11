//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_982_div2_c.rs
//@data      2024/11/11 06:36:59
#[macro_export]
macro_rules! cin {
    ()=>{{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().to_string()
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
fn main() {
    // let t = 1;
    let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let n = cin!(usize);
    let qwq = cin!([i64; n]);
    let mut adj = std::collections::HashMap::new();
    for i in 1..n as i64 {
        let u = qwq[i as usize] + i;
        let v = u + i;
        adj.entry(u).or_insert(Vec::new()).push(v);
    }
    let dfs = || {
        let mut vis = std::collections::HashSet::new();
        let mut stk = vec![n as i64];
        while let Some(u) = stk.pop() {
            if !vis.contains(&u) {
                vis.insert(u);
                // println!("{:?} , {}", adj, u);
                for v in adj.get(&u).unwrap_or(&vec![u]) {
                    stk.push(*v)
                }
            }
        }
        *vis.iter().max().unwrap()
    };
    println!("{}", dfs());
}
