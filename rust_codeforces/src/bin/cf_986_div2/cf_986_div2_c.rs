//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_986_div2_c.rs
//@data      2024/11/11 00:41:28
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
    let (n, m, v) = cin!(usize, usize, i64);
    let qwq = cin!([i64; n]);
    let mut qaq = vec![0; n + 1];
    for i in 0..n {
        qaq[i + 1] = qaq[i] + qwq[i];
    }

    // 定义区间和查询函数
    let querry = |l: usize, r: usize| qaq[r] - qaq[l];

    // 构建 f 数组，从左往右找到每个满足条件的子区间右端点
    let mut f = vec![0i64; m + 1];
    let mut j = 0;
    for i in 1..=m {
        while j as usize <= n && querry(f[i - 1] as usize, j as usize) < v {
            j += 1;
        }
        f[i] = j;
    }

    // 构建 g 数组，从右往左找到每个满足条件的子区间左端点
    let mut g = vec![n as i64; m + 1];
    let mut j = n as i64;
    for i in 1..=m {
        while j >= 0 && querry(j as usize, g[i - 1] as usize) < v {
            j -= 1;
        }
        g[i] = j;
    }

    // 查找满足条件的最大区间和
    let mut ans = -1;
    for i in 0..=m {
        if f[i] <= n as i64 && g[m - i] >= 0 && f[i] <= g[m - i] {
            ans = ans.max(querry(f[i] as usize, g[m - i] as usize));
        }
    }

    // 输出结果
    println!("{}", ans);
}
