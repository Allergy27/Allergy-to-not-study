//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p1304.rs
//@data      2024/10/28 02:02:46
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
    const M: usize = 100005;
    let mut vis = [true; M];
    let mut prime = vec![];
    let mut get_prime = || {
        for i in 2..M {
            //质数
            if vis[i] {
                prime.push(i);
            }
            for &j in &prime {
                if i * j >= M {
                    break;
                }
                vis[i * j] = false;
                if i % j == 0 {
                    break;
                }
            }
        }
    };
    get_prime();
    // println!("{:?}", prime);
    let n = cin().parse::<usize>().unwrap();
    let prime_set = std::collections::HashSet::<usize>::from_iter(prime.iter().cloned());
    for i in (4..=n).step_by(2) {
        for &x in &prime {
            if prime_set.contains(&(i - x)) {
                println!("{}={}+{}", i, x, i - x);
                break;
            }
        }
    }
}
