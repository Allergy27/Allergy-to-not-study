//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1021_new.rs
//@data      2024/11/04 12:17:22
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
    let t = 1;
    //let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (n, m) = cin!(usize, usize);
    const INF: usize = 2704;
    let dp = |a: &Vec<usize>| -> usize {
        let mut f = [INF; INF];
        a.iter().for_each(|&x| f[x] = 1);
        for i in 1.. {
            a.iter().take_while(|&&x| i > x).for_each(|&x| f[i] = f[i].min(f[i - x] + 1));
            if f[i] > n {
                return i - 1;
            }
        }
        unreachable!()
    };
    let dfs = || {
        let mut qwq = Vec::with_capacity(m);
        qwq.push(1);
        let mut ans = (n, qwq);
        let mut stk = Vec::new();
        stk.push(ans.clone());
        while let Some(res) = stk.pop() {
            let x = &res.1;
            if x.len() == m {
                if res.0 > ans.0 {
                    ans = res;
                }
            } else {
                for i in *x.last().unwrap() + 1..=res.0 + 1 {
                    let mut tmp = x.clone();
                    tmp.push(i);
                    stk.push((dp(&tmp), tmp));
                }
            }
        }
        ans
    };
    let (ans, arr) = dfs();
    arr.iter().for_each(|&x| print!("{} ", x));
    println!("\nMAX={}", ans);
}
