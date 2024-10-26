//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace leetcode/1962.rs
//@data      2023/12/23 11:35:28

fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let mut qwq = vec![1391, 5916];
    let k = 5;
    let n = qwq.len() - 1;
    let mut i = n;
    qwq.sort_unstable();
    for _ in 0..k {
        if qwq[n - 1] == 0 {
            break;
        }
        if i > 0 && qwq[i - 1] <= qwq[n] {
            qwq[i] = (qwq[i] + 1) / 2;
            i -= 1
        } else {
            qwq = merge(&qwq, i);
            i = n
        }
    }
    println!("{}", qwq.iter().sum::<i32>())
}
fn merge(v: &[i32], m: usize) -> Vec<i32> {
    let (mut l, mut r, n) = (0, m, v.len());
    let mut qwq: Vec<i32> = vec![0; n];
    for x in qwq.iter_mut() {
        if l != m && (r == n || v[l] < v[r]) {
            *x = v[l];
            l += 1;
        } else if r != n && (l == m || v[l] >= v[r]) {
            *x = v[r];
            r += 1;
        }
    }
    qwq
}
