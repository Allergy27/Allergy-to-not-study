//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_984_div3_d_re.rs
//@data      2024/11/11 05:30:21
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
    let mut qwq = Vec::with_capacity(n);
    for _ in 0..n {
        qwq.push(cin!().chars().collect::<Vec<_>>())
    }

    let mut ans = 0;
    for i in 0..(n / 2).min(m / 2) {
        let mut s = Vec::new();
        for x in i..m - i - 1 {
            s.push(qwq[i][x])
        }
        for y in i..n - i - 1 {
            s.push(qwq[y][m - i - 1])
        }
        for x_rev in (i + 1..m - i).rev() {
            s.push(qwq[n - i - 1][x_rev])
        }
        for y_rev in (i + 1..n - i).rev() {
            s.push(qwq[y_rev][i])
        }
        let t = s.len();

        (0..t).for_each(|i| {
            if s[i] == '1'
                && s[(i + 1) % t] == '5'
                && s[(i + 2) % t] == '4'
                && s[(i + 3) % t] == '3'
            {
                ans += 1
            }
        });
    }
    println!("{}", ans);
}
