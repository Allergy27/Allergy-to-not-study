//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_985_glb_d_re.rs
//@data      2024/11/11 03:54:24
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
    let mut qwq = vec![std::collections::HashSet::new(); n + 1];
    for _ in 0..m {
        let (u, v) = cin!(usize, usize);
        qwq[u].insert(v);
        qwq[v].insert(u);
    }
    //记录操作
    let mut ans = Vec::new();

    for i in 1..=n {
        while qwq[i].len() >= 2 {
            let u = *qwq[i].iter().next().unwrap();
            qwq[i].remove(&u);
            let v = *qwq[i].iter().next().unwrap();
            qwq[i].remove(&v);
            qwq[u].remove(&i);
            qwq[v].remove(&i);
            ans.push((i, u, v));
            if qwq[u].contains(&v) {
                qwq[u].remove(&v);
                qwq[v].remove(&u);
            } else {
                qwq[u].insert(v);
                qwq[v].insert(u);
            }
        }
    }
    //空组件
    let mut zro = Vec::new();
    //一条边组件
    let mut one = Vec::new();
    for (i, elem) in qwq.iter().enumerate().skip(1) {
        if elem.is_empty() {
            zro.push(i);
        } else if *elem.iter().next().unwrap() > i {
            one.push((i, *elem.iter().next().unwrap()));
        }
    }
    if !one.is_empty() {
        // println!("{:?}", one);
        let (u, mut v) = one.pop().unwrap();
        for x in zro {
            ans.push((u, x, v));
            v = x;
        }
        for (a, b) in one {
            ans.push((v, a, b));
        }
    }
    println!("{}", ans.len());
    ans.iter().for_each(|(a, b, c)| println!("{} {} {}", a, b, c));
}
