//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_985_glb_d.rs
//@data      2024/11/09 23:58:32
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
    let (n, m) = cin!(usize, usize);
    let mut edge = vec![std::collections::HashSet::new(); n + 1];

    for _ in 0..m {
        let (u, v) = cin!(usize, usize);
        edge[u].insert(v);
        edge[v].insert(u);
    }

    let mut ans = Vec::new();

    for i in 1..=n {
        //清理大于2的组件
        while edge[i].len() >= 2 {
            let u = *edge[i].iter().next().unwrap();
            edge[i].remove(&u);
            let v = *edge[i].iter().next().unwrap();
            edge[i].remove(&v);

            edge[u].remove(&i);
            edge[v].remove(&i);
            ans.push((i, u, v));

            if edge[u].contains(&v) {
                edge[u].remove(&v);
                edge[v].remove(&u);
            } else {
                edge[u].insert(v);
                edge[v].insert(u);
            }
        }
    }

    let mut s = Vec::new();
    let mut p = Vec::new();

    for (i, elem) in edge.iter().enumerate().skip(1) {
        if elem.is_empty() {
            s.push(i);
        } else if *elem.iter().next().unwrap() > i {
            p.push((i, *elem.iter().next().unwrap()));
        }
    }

    if !p.is_empty() {
        let (x, mut y) = p.pop().unwrap();
        for &u in &s {
            ans.push((x, y, u));
            y = u;
        }
        for (u, v) in p {
            ans.push((y, u, v));
        }
    }
    println!("{}", ans.len());
    for (x, y, z) in ans {
        println!("{} {} {}", x, y, z);
    }
}
