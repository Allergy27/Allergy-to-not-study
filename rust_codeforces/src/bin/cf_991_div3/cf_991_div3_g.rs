//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_991_div3_g.rs
//@data      2024/12/06 02:46:20
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
    let mut qwq = vec![Vec::new(); n];
    for _ in 1..n {
        let (u, v) = cin!(usize, usize);
        qwq[u - 1].push(v - 1);
        qwq[v - 1].push(u - 1);
    }
    let mut dp = vec![0; n];
    let mut ans = 1;
    fn dfs(x: usize, p: isize, adj: &Vec<Vec<usize>>, dp: &mut Vec<isize>, ans: &mut isize) {
        let v = adj[x].len() as isize - 2;
        dp[x] = v;
        *ans = *ans.max(&mut (v + 2));
        for &y in &adj[x] {
            if y == p as usize {
                continue;
            }
            dfs(y, x as isize, adj, dp, ans);
            *ans = *ans.max(&mut (dp[x] + dp[y] + 2));
            dp[x] = dp[x].max(v + dp[y]);
        }
    }
    dfs(0, -1, &qwq, &mut dp, &mut ans);
    println!("{ans}")
}
