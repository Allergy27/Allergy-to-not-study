//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/cf_984_div3_d.rs
//@data      2024/11/05 23:36:51
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
    let (n, m) = cin!(usize, usize);
    let mut qwq = Vec::with_capacity(n);
    for _ in 0..n {
        qwq.push(cin!().chars().collect::<Vec<_>>())
    }

    let mut res = Vec::new();
    let round = n.min(m) / 2;

    for rd in 0..round {
        let mut tmp = Vec::new();

        // 上边界
        for j in rd..m - rd {
            tmp.push(qwq[rd][j]);
        }
        // 右边界
        for row in qwq.iter().skip(rd + 1).take(n - 2 * rd - 1) {
            tmp.push(row[m - rd - 1]);
        }
        // 下边界
        if n - rd - 1 > rd {
            for j in (rd..m - rd - 1).rev() {
                tmp.push(qwq[n - rd - 1][j]);
            }
        }
        // 左边界
        if m - rd - 1 > rd {
            for i in (rd + 1..n - rd - 1).rev() {
                tmp.push(qwq[i][rd]);
            }
        }

        res.push(tmp);
    }

    let mut ans = 0;
    for tmp in res {
        let ln = tmp.len();
        for i in 0..ln {
            if tmp[i] == '1'
                && tmp[(i + 1) % ln] == '5'
                && tmp[(i + 2) % ln] == '4'
                && tmp[(i + 3) % ln] == '3'
            {
                ans += 1;
            }
        }
    }
    println!("{}", ans);
}
