//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1027.rs
//@data      2024/11/04 18:24:54
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
    let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (n, t, a, b) = cin!(usize, i64, usize, usize);
    let mid_find = |a: (f64, f64), b: (f64, f64), c: (f64, f64)| (a.0 + b.0 - c.0, a.1 + b.1 - c.1);
    let dist = |a: (f64, f64), b: (f64, f64)| -> f64 {
        ((a.0 - b.0) * (a.0 - b.0) + (a.1 - b.1) * (a.1 - b.1)).sqrt()
    };
    let ffp = |a: (f64, f64), b: (f64, f64), c: (f64, f64)| -> (f64, f64) {
        let dis_1 = (a.0 - b.0) * (a.0 - b.0) + (a.1 - b.1) * (a.1 - b.1);
        let dis_2 = (a.0 - c.0) * (a.0 - c.0) + (a.1 - c.1) * (a.1 - c.1);
        let dis_3 = (b.0 - c.0) * (b.0 - c.0) + (b.1 - c.1) * (b.1 - c.1);
        match dis_1.max(dis_2).max(dis_3) {
            x if x == dis_1 => mid_find(a, b, c),
            x if x == dis_2 => mid_find(a, c, b),
            _ => mid_find(b, c, a),
        }
    };
    let mut arr = Vec::new();
    let mut fee = Vec::new();
    let mut qwq = vec![vec![0.0; 4 * n + 1]; 4 * n + 1];
    for _ in 0..n {
        let (x1, y1, x2, y2, x3, y3, v) = cin!(f64, f64, f64, f64, f64, f64, f64);
        let (x4, y4) = ffp((x1, y1), (x2, y2), (x3, y3));
        arr.push((x1, y1));
        arr.push((x2, y2));
        arr.push((x3, y3));
        arr.push((x4, y4));
        fee.push(v);
    }
    for i in 0..4 * n {
        for j in i + 1..4 * n {
            if i / 4 != j / 4 {
                qwq[i][j] = dist(arr[i], arr[j]) * t as f64;
                qwq[j][i] = qwq[i][j];
            } else {
                qwq[i][j] = dist(arr[i], arr[j]) * fee[i / 4];
                qwq[j][i] = qwq[i][j];
            }
        }
    }
    for k in 0..4 * n {
        for i in 0..4 * n {
            for j in 0..4 * n {
                if qwq[i][j] > qwq[i][k] + qwq[k][j] {
                    qwq[i][j] = qwq[i][k] + qwq[k][j];
                }
            }
        }
    }
    let mut ans = f64::INFINITY;
    for i in 0..4 {
        for j in 0..4 {
            ans = ans.min(qwq[(a - 1) * 4 + i][(b - 1) * 4 + j])
        }
    }
    println!("{:.1}", ans);
}
