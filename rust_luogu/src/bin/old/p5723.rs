//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p5723.rs
//@data      2023/12/13 20:52:55
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n:usize = input.trim().parse().unwrap();
    if n==1||n==0{println!("{}",0);return;}
    let mut result = vec![0; n + 1];
    let mut is_prime = vec![true; n + 1];
    let mut count = 0;
    for i in 2..=n {
        if is_prime[i] {
            result[count] = i;
            count += 1;
        }

        let mut j = 0;
        while result[j] * i <= n {
            is_prime[result[j] * i] = false;
            if (i % result[j]) == 0 {
                break;
            }
            j += 1;
        }
    }
    let ans=(0..=count).fold((0,0),|x,_|if x.0+result[x.1]<=n{(x.0+result[x.1],x.1+1)}else {x}).1;
    (0..ans).for_each(|x|println!("{}",result[x]));
    println!("{}",ans);
}
