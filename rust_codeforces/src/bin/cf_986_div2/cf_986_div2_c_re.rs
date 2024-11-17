//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_986_div2_c_re.rs
//@data      2024/11/16 00:55:12
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
    let (n, m, v) = cin!(usize, usize, usize);
    let qwq = cin!([usize; n]);
    let mut qaq = vec![0; n + 1];
    for i in 0..n {
        qaq[i + 1] = qaq[i] + qwq[i];
    }
    let query = |l: usize, r: usize| qaq[r] - qaq[l];
    // 从前往后切，第m的右端点（开
    let mut f = vec![0; m + 1];
    let mut tmp = 0;
    for i in 1..=m {
        while tmp as usize <= n && query(f[i - 1] as usize, tmp as usize) < v {
            tmp += 1;
        }
        f[i] = tmp;
    }
    // 从后往前切，第m的左端点（闭
    let mut g = vec![n as i32; m + 1];
    tmp = n as i32;
    for i in 1..=m {
        while tmp >= 0 && query(tmp as usize, g[i - 1] as usize) < v {
            tmp -= 1;
        }
        g[i] = tmp;
    }
    let mut ans = -1;
    for i in 0..=m {
        // 符合条件的区间计算能获得的蛋糕
        if f[i] <= n as i32 && g[m - i] >= 0 && f[i] <= g[m - i] {
            ans = ans.max(query(f[i] as usize, g[m - i] as usize) as i32)
        }
    }
    println!("{ans}");
}
