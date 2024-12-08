//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/abc_383_a.rs
//@data      2024/12/07 19:59:52
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
    let t = 1;
    //let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (n, m, d) = cin!(usize, usize, i64);
    let mut arr = vec![Vec::new(); n];
    for x in &mut arr {
        *x = cin!([char]);
    }
    let dis = |x1: usize, y1: usize, x2: usize, y2: usize| {
        (x1 as i64 - x2 as i64).abs() + (y1 as i64 - y2 as i64).abs()
    };
    let mut ans = 0;
    for i in 0..n {
        for j in 0..m {
            for p in 0..n {
                for q in 0..m {
                    if !(i == p && j == q) && arr[i][j] == '.' && arr[p][q] == '.' {
                        let mut tmp = 0;
                        //加湿器の位置が違う
                        for k in 0..n {
                            for l in 0..m {
                                if arr[k][l] == '.'
                                    && (dis(i, j, k, l) <= d || dis(p, q, k, l) <= d)
                                {
                                    tmp += 1;
                                }
                            }
                        }
                        // println!("{i} {j} {p} {q} {:?} {tmp}", (arr[i][j], arr[p][q]));
                        ans = ans.max(tmp);
                    }
                }
            }
        }
    }
    println!("{ans}")
}
