//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace study/insert.rs
//@data      2024/01/21 17:45:33
fn _cin() -> String {
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
    let mut v = vec![0, 1, 2, 4, 5, 6, 7, 0]; //A
    let (n, mut i) = (3, 6); //B
    while v[i] > n && i > 0 {
        //D
        v[i + 1] = v[i];
        i -= 1;
    }
    let pos = i; //C
    v[pos + 1] = n; //E
    print!("{:?}", v)
}
