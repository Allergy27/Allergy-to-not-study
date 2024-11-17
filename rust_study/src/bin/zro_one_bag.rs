//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/zro_one_bag.rs
//@data      2024/11/13 13:18:08
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
    println!("请输入物品数量和背包容量:");
    let (n, m) = cin!(usize, usize);
    println!("请依次在每行输入物品的重量和价值:");
    let qwq = (0..n).map(|_| cin!(usize, usize)).collect::<Vec<_>>();

    //01背包问题 --回溯法O(2^n)暴力解
    let dp_back = || {
        //st模拟dfs
        let mut st = Vec::new();
        let mut ans = 0;
        st.push((0, 0, m));
        let mut time_count = 0;
        while let Some((tmp, t, c)) = st.pop() {
            time_count += 1;
            if t == n {
                ans = ans.max(tmp);
            } else {
                if c >= qwq[n - t - 1].0 {
                    st.push((tmp + qwq[n - t - 1].1, t + 1, c - qwq[n - t - 1].0))
                }
                st.push((tmp, t + 1, c))
            }
        }
        (ans, time_count)
    };

    //01背包问题 --分支界限法O(2^n)求解
    let dp_binary = || {
        let mut qaq = qwq.clone();
        qaq.sort_unstable_by(|a, b| (b.1 * a.0).cmp(&(a.1 * b.0)));
        let mut st = std::collections::BinaryHeap::new();
        //界限函数
        let ub = |w: usize, v: usize, i: usize| v + (m - w) * (qaq[i].1 / qaq[i].0);
        st.push((ub(0, 0, 0), 0, 0, 0));
        let mut tc = 0;
        while let Some((tmp, w, v, i)) = st.pop() {
            tc += 1;
            //叶子节点
            if i == n {
                // println!("{tc}");
                return (if tmp == ub(w, v, i - 1) { tmp } else { v }, tc);
            }
            let tmp = ub(w, v, i);
            if w + qwq[i].0 <= m {
                st.push((tmp, w + qaq[i].0, v + qaq[i].1, i + 1));
            }
            st.push((tmp, w, v, i + 1));
            // println!("{:?}", st);
        }
        (0, tc)
    };

    //01背包问题 --构造dp表O(nm)线性解
    let mut dp = vec![0; m + 1];
    let mut t3 = 0;
    for (w, v) in &qwq {
        for i in (*w..=m).rev() {
            t3 += 1;
            dp[i] = dp[i].max(dp[i - w] + v)
        }
    }

    let (_zro_1, t1) = dp_back();
    let (_zro_2, t2) = dp_binary();
    let mn = (n as f64).log2();
    println!("t1:{t1}\nt2:{:.2}\nt3:{t3}", t2 as f64 * mn);
    println!("{}", dp[m]);
}
