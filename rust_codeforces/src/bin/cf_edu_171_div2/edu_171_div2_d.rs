//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/edu_171_div2_d.rs
//@data      2024/10/29 07:25:04
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let t = cin().parse::<i32>().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let n = cin().parse::<i64>().unwrap();
    let qwq = cin()
        .split_whitespace()
        .map(|s| s.parse::<i64>().unwrap())
        .collect::<Vec<_>>();
    //Step 1: O(n)预处理
    let mut qaq = vec![0; n as usize + 1]; //前缀和
    for i in 0..n {
        qaq[i as usize + 1] = qwq[i as usize] + qaq[i as usize];
    }
    let mut w = vec![0; n as usize + 1]; //b的前缀和 横向
    let mut h = vec![0; n as usize + 1];
    let mut arr = vec![0; n as usize + 1];
    let num = (0..=n).map(|i| (n + n - i + 1) * i / 2).collect::<Vec<_>>();
    for i in 0..n {
        h[i as usize + 1] = h[i as usize] + qwq[i as usize] * (n - i)
    }
    for i in 0..n {
        w[i as usize + 1] = w[i as usize] + qaq[i as usize + 1];
    }
    let t = |l: i64, r: i64| w[r as usize] - h[l as usize - 1] + (n - r) * qaq[l as usize - 1];
    for i in 1..=n {
        arr[i as usize] = arr[i as usize - 1] + t(i, n);
    }

    //Step 2: O(logn)分区间，O(1)求区间和，共q次，总复杂度O(n+qlogn)
    let q = cin().parse::<i64>().unwrap();

    for _ in 0..q {
        let mut ans = 0;
        let (l, r) = cin()
            .split_whitespace()
            .fold((0, 0), |x, y| (x.1, y.parse::<i64>().unwrap()));
        let nl = num.partition_point(|&x| x < l) as i64 - 1;
        let nr = num.partition_point(|&x| x < r) as i64;
        let (fnl, fnr) = (n - num[nl as usize + 1], n - num[nr as usize]);
        if nl + 1 == nr {
            ans += t(nr, fnr + r) - t(nr, fnr + l - 1);
        } else {
            ans += t(nl + 1, n) - t(nl + 1, fnl + l - 1);
            ans += arr[nr as usize - 1] - arr[nl as usize + 1];
            ans += t(nr, fnr + r)
        }
        println!("{}", ans);
    }
}
