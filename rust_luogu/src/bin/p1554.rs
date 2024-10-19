//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1554.rs
//@data      2023/12/20 12:56:29
fn input() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t=1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_|solve());
}
fn solve() {
    let input = input();
    let mut input =input.split_whitespace();
    let (a, b): (i64, i64) = (
        input.next().unwrap().parse().unwrap(),
        input.next().unwrap().parse().unwrap(),
    );
    let mut qwq=[0; 10];
    for mut num in a..=b{
        while num>0{
            qwq[(num%10)as usize]+=1;
            num/=10;
        }
    }
    (0..10).for_each(|x|print!("{} ",qwq[x]))
}
