//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p5726.rs
//@data      2024/10/27 19:31:41
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
    const M: usize = 100007;
    let mut vis = [false; M];
    let mut prime = vec![];
    let mut k = 0;
    let mut sieve = || {
        for i in 2..M {
            if !vis[i] {
                prime.push(i);
                k += 1;
            }
            for j in 0..k {
                if prime[j] * i >= M {
                    break;
                }
                vis[prime[j] * i] = true;
                if i % prime[j] == 0 {
                    break;
                }
            }
        }
    };

    let _ = cin().parse::<usize>().unwrap();
    let qwq = cin().split_whitespace().map(|s| s.parse().unwrap()).collect::<Vec<usize>>();
    sieve();
    let prime = std::collections::HashSet::<usize>::from_iter(prime);
    qwq.iter().filter(|&x| prime.contains(x)).for_each(|x| print!("{} ", x));
}
