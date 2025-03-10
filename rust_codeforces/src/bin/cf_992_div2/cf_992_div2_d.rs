//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_992_div2_d.rs
//@data      2024/12/08 23:59:51
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
        qwq[u - 1].push(v - 1);
        qwq[v - 1].push(u - 1);
    }
    let mut ans = vec![0; n];
    fn dfs(x: usize, p: usize, cur: &mut i64, qwq: &Vec<Vec<usize>>, ans: &mut Vec<i64>) {
        ans[x] = *cur;
        let mut flag = true;
        for &y in &qwq[x] {
            if y != p {
                if flag {
                    flag = false;
                    *cur += 1;
                    dfs(y, x, cur, qwq, ans);
                    *cur += 1;
                } else {
                    *cur += 2;
                    dfs(y, x, cur, qwq, ans);
                }
            }
        }
    }
    dfs(0, n, &mut 1, &qwq, &mut ans);
    (0..n).for_each(|i| {
        print!("{} ", ans[i]);
    });
    println!();
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
