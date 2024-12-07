//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/edu_172_div2_c.rs
//@data      2024/12/02 23:02:01
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
    let (n, m) = cin!(usize, i64);
    let s = cin!().chars().collect::<Vec<char>>();
    let mut qwq = vec![(0, 0); n];
    let mut tmp = (0, 0);
    for (i, x) in s.iter().enumerate().rev() {
        if *x == '0' {
            tmp.0 += 1;
        } else {
            tmp.1 += 1;
        }
        qwq[i] = tmp;
    }
    let mut ans = 1;
    let mut res = 0;
    let mut st = std::collections::BinaryHeap::new();
    for (i, (a, b)) in qwq.into_iter().enumerate() {
        if s[i] == '0' {
            st.push(b - a + 1);
        } else if s[i] == '1' {
            st.push(b - a - 1);
        }
    }
    while let Some(x) = st.pop() {
        // println!("!~!{x}");
        if x > 0 {
            res += x;
            ans += 1;
            if res >= m {
                println!("{ans}");
                return;
            }
        } else {
            break;
        }
    }
    println!("-1");
}
