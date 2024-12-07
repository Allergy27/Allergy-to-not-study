//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_964_div4_e.rs
//@data      2024/12/03 06:54:53
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
    // let t = cin!(i64);

    (0..t).for_each(|_| solve());
}
fn solve() {
    let t = cin!(usize);
    const MAXN: usize = 200007;
    let mut qwq = vec![0; MAXN + 1];
    (1..=MAXN).for_each(|i| {
        let mut cot = 0;
        let mut tmp = i;
        while tmp > 0 {
            tmp /= 3;
            cot += 1;
        }
        qwq[i] = cot;
    });
    let mut qaq = vec![0; MAXN + 1];
    for i in 1..=MAXN {
        qaq[i] = qaq[i - 1] + qwq[i];
    }

    for _ in 0..t {
        let (l, r) = cin!(usize, usize);
        let ans = qaq[r] - qaq[l - 1] + qwq[l];
        println!("{ans}")
    }
}
