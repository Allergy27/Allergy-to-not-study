//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/abc_381_c.rs
//@data      2024/11/22 20:12:10
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
    let (n, m) = cin!(usize, usize);
    let s = cin!().bytes().collect::<Vec<_>>();
    let mut pre = vec![0; n + 1];
    let mut suf = vec![0; n + 1];
    let mut qwq = Vec::new();
    for i in 1..n {
        if s[i] == b'/' {
            qwq.push(i);
        }
        pre[i] = pre[i - 1] + (s[i - 1] == b'1') as i32;
    }
    for i in (0..n).rev() {
        suf[i] = suf[i + 1] + (s[i] == b'2') as i32;
    }
    for _ in 0..m {
        let (l, r) = cin!(usize, usize);
        if l != r {
            let ckl = qwq.partition_point(|x| *x < (l - 1));
            let ckr = qwq.partition_point(|x| *x <= (r - 1)) - 1;

            let mut ans = 0;
            if ckl > ckr {
                println!("0");
                continue;
            }
            for &x in qwq.iter().skip(ckl).take(ckr - ckl + 1) {
                ans = ans.max((pre[x + 1] - pre[l - 1]).min(suf[x] - suf[r]) * 2 + 1);
                // println!("!!!{:?}!!!{:?}", (pre[x], suf[x]), (pre[l], suf[r]));
            }
            println!("{}", ans);
        } else {
            let x = l - 1;
            if s[x] == b'/' {
                println!("1");
            } else {
                println!("0");
            }
        }
    }
}
