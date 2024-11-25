//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/p4924.rs
//@data      2024/11/18 12:06:36
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
    let mut qwq = (1..=(n * n)).fold(vec![Vec::with_capacity(n); n], |mut ans, x| {
        ans[(x - 1) / n].push(x);
        ans
    });
    let mut tmp = vec![vec![0; n]; n];
    for _ in 0..m {
        let (x, y, r, z) = cin!(usize, usize, usize, usize);
        let (x, y) = (x - 1, y - 1);
        if z == 0 {
            for (i, row) in qwq.iter().enumerate().skip(x - r).take(2 * r + 1) {
                for (j, &val) in row.iter().enumerate().skip(y - r).take(2 * r + 1) {
                    tmp[x - y + j][x + y - i] = val;
                }
            }
            for (i, row) in tmp.iter().enumerate().skip(x - r).take(2 * r + 1) {
                for (j, &val) in row.iter().enumerate().skip(y - r).take(2 * r + 1) {
                    qwq[i][j] = val;
                }
            }
        } else {
            for (i, row) in qwq.iter().enumerate().skip(x - r).take(2 * r + 1) {
                for (j, &val) in row.iter().enumerate().skip(y - r).take(2 * r + 1) {
                    tmp[x + y - j][y - x + i] = val;
                }
            }
            for (i, row) in tmp.iter().enumerate().skip(x - r).take(2 * r + 1) {
                for (j, &val) in row.iter().enumerate().skip(y - r).take(2 * r + 1) {
                    qwq[i][j] = val;
                }
            }
        }
    }
    for row in qwq.iter() {
        for &val in row.iter() {
            print!("{} ", val);
        }
        println!();
    }
}
