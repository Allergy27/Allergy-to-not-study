//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_992_div2_d.rs
//@data      2024/12/08 23:59:51
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
fn main() {
    // let t = 1;
    let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let n = cin!(usize);
    let mut qwq = vec![Vec::new(); n + 1];
    for _ in 0..n - 1 {
        let (u, v) = cin!(usize, usize);
        qwq[u].push(v);
        qwq[v].push(u);
    }
    let mut ans = vec![0; n + 1];
    let mut que = std::collections::VecDeque::new();
    let mut vis = vec![false; n + 1];
    let mut odd = 1;
    let mut even = 2;

    que.push_back((1, 0)); // (node, depth)
    vis[1] = true;

    while let Some((x, t)) = que.pop_front() {
        if t % 2 == 0 {
            ans[x] = even;
            even += 2;
        } else {
            ans[x] = odd;
            odd += 2;
        }

        for &y in &qwq[x] {
            if !vis[y] {
                vis[y] = true;
                que.push_back((y, t + 1));
            }
        }
    }

    (1..=n).for_each(|i| {
        print!("{} ", ans[i]);
    });
    println!();
}
