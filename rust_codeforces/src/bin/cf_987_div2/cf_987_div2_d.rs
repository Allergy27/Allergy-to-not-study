//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/cf_987_div2_d.rs
//@data      2024/11/15 23:20:58
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
    let n = cin!(usize);
    let qwq = cin!([i32; n]);
    let mut pre = vec![-1; n + 1];
    for i in 0..n {
        pre[i + 1] = pre[i].max(qwq[i])
    }
    let mut suf = vec![n as i32 + 1; n + 1];
    for i in (0..n).rev() {
        suf[i] = suf[i + 1].min(qwq[i])
    }
    let mut ans = vec![-1; n];
    let mut last = 0;
    // println!("!!!!!!!!check!!!!!!!!");
    for i in 1..=n {
        // println!("{last} {i} {:?} {:?} {:?}", ans, pre[i], suf[i]);
        //往右找不到更小值，说明当前值最小
        if pre[i] <= suf[i] {
            for elem in ans.iter_mut().take(i).skip(last) {
                *elem = pre[i];
            }
            last = i;
        }
    }
    ans.iter().for_each(|x| print!("{x} "));
    println!()
}
