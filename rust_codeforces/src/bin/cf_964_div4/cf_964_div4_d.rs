//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_964_div4_d.rs
//@data      2024/12/03 06:45:29
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
    let mut qwq = cin!().chars().collect::<Vec<_>>();
    let t = cin!().chars().collect::<Vec<_>>();
    let mut tmp = 0;
    let n = qwq.len();
    let m = t.len();
    (0..n).for_each(|i| {
        if tmp < m && qwq[i] == t[tmp] {
            tmp += 1;
        } else if qwq[i] == '?' {
            if tmp < m {
                qwq[i] = t[tmp];
                tmp += 1;
            } else {
                qwq[i] = 'a';
            }
        }
    });
    if tmp == m {
        println!("YES");
        println!("{}", qwq.iter().collect::<String>());
    } else {
        println!("NO");
    }
}
