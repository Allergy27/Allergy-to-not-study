//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/p1464.rs
//@data      2024/11/16 02:49:47
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
    let mut qwq = vec![vec![vec![0; 27]; 27]; 27];
    loop {
        let (a, b, c) = cin!(i64, i64, i64);
        if (a, b, c) == (-1, -1, -1) {
            break;
        }
        println!("w({a}, {b}, {c}) = {}", w(&mut qwq, a, b, c))
    }
}
fn w(qwq: &mut Vec<Vec<Vec<i64>>>, a: i64, b: i64, c: i64) -> i64 {
    if a <= 0 || b <= 0 || c <= 0 {
        1
    } else if a > 20 || b > 20 || c > 20 {
        w(qwq, 20, 20, 20)
    } else if a < b && b < c {
        if qwq[a as usize][b as usize][c as usize] == 0 {
            qwq[a as usize][b as usize][c as usize] =
                w(qwq, a, b, c - 1) + w(qwq, a, b - 1, c - 1) - w(qwq, a, b - 1, c);
        }
        qwq[a as usize][b as usize][c as usize]
    } else {
        if qwq[a as usize][b as usize][c as usize] == 0 {
            qwq[a as usize][b as usize][c as usize] =
                w(qwq, a - 1, b, c) + w(qwq, a - 1, b - 1, c) + w(qwq, a - 1, b, c - 1)
                    - w(qwq, a - 1, b - 1, c - 1);
        }
        qwq[a as usize][b as usize][c as usize]
    }
}
