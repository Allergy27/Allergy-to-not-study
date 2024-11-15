//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/p1433.rs
//@data      2024/11/14 21:32:18
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
    let n = cin!(usize);
    let mut qwq = vec![vec![0.0; n]; n];
    let mut point = Vec::with_capacity(n);
    for _ in 0..n {
        point.push(cin!(f64, f64));
    }
    let mut dp = vec![vec![f64::INFINITY; n]; 1 << n];
    for i in 0..n {
        let x1 = point[i].0;
        let y1 = point[i].1;
        for j in i + 1..n {
            let x2 = point[j].0;
            let y2 = point[j].1;
            qwq[i][j] = ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)).sqrt();
            qwq[j][i] = qwq[i][j];
        }
        dp[1 << i][i] = (x1 * x1 + y1 * y1).sqrt();
    }
    for status in 0..1 << n {
        for i in 0..n {
            if status & (1 << i) == 0 {
                continue;
            }
            for j in 0..n {
                if status & (1 << j) == 0 || i == j {
                    continue;
                }
                dp[status][i] = dp[status][i].min(dp[status - (1 << i)][j] + qwq[i][j])
            }
        }
    }
    println!(
        "{:.2}",
        dp[(1 << n) - 1].iter().fold(f64::INFINITY, |ans, x| { ans.min(*x) })
    )
}
