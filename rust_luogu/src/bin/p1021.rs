//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1021.rs
//@data      2023/12/21 14:14:52
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (n, k) = cin().split_whitespace().fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    let mut qwq = vec![1];
    let ans = dfs(&mut qwq, n, k, n + 1);
    ans.1.iter().for_each(|x| print!("{} ", x));
    println!("\nMAX={}", ans.0);
}
fn dp(a: &[usize], n: usize) -> usize {
    let mut f = [5270; 5270];
    a.iter().for_each(|&x| f[x] = 1);
    for i in 1.. {
        a.iter().take_while(|t| i > **t).for_each(|x| f[i] = f[i].min(f[i - *x] + 1));
        if f[i] > n as i32 {
            return i - 1;
        }
    }
    unreachable!()
}
fn dfs(a: &mut Vec<usize>, n: usize, k: usize, mx: usize) -> (usize, Vec<usize>) {
    if a.len() == k {
        return (mx, a.to_vec());
    }
    (a[a.len() - 1] + 1..=mx + 1).fold((0, a.to_vec()), |x, i| {
        a.push(i);
        let p = dp(a, n);
        let q = dfs(a, n, k, p);
        a.pop();
        (x.0.max(q.0), if q.0 > x.0 { q.1 } else { x.1 })
    })
}
