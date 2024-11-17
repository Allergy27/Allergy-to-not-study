//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1036.rs
//@data      2024/11/08 12:40:34
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
    let (n, k) = cin!(i64, i64);
    let qwq = cin!([i64; n]);
    // 判断素数
    let check = |x: i64| {
        for i in 2..=x {
            if i * i > x {
                break;
            }
            if x % i == 0 {
                return false;
            }
        }
        true
    };
    let dfs = || {
        let mut ans = 0;
        //(状态 x, 位数 n, 1个数 m)
        let mut stk = vec![(0, 1, 0), (1, 1, 1)];
        while let Some((x, t, m)) = stk.pop() {
            if t == n && m == k {
                let mut tmp = x;
                let mut sum = 0;
                for i in 0..t {
                    if tmp % 2 == 1 {
                        sum += qwq[i as usize];
                    }
                    tmp >>= 1;
                }
                // println!("{}", sum);
                ans += if check(sum) { 1 } else { 0 };
            } else if t != n {
                //不选
                stk.push((x << 1, t + 1, m));
                if m < k {
                    stk.push((x << 1 | 1, t + 1, m + 1));
                }
            }
        }
        ans
    };
    println!("{}", dfs());
}
