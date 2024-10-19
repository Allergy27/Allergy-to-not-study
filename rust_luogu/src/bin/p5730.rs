//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p5730.rs
//@data      2023/12/20 10:52:51
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    let _ = (0..t).for_each(|_| solve());
}
fn solve() {
    let scanner = [
        [63, 49, 63, 32], //0
        [32, 32, 63, 32], //1
        [61, 53, 55, 32], //2
        [53, 53, 63, 32], //3
        [39, 36, 63, 32], //4
        [55, 53, 61, 32], //5
        [63, 53, 61, 32], //6
        [33, 33, 63, 32], //7
        [63, 53, 63, 32], //8
        [55, 53, 63, 32], //9
    ];
    let n: usize = cin().parse().unwrap();
    let qwq: Vec<Vec<char>> = cin()
        .chars()
        .flat_map(|s| print_scan(scanner[s as usize ^ 48]))
        .collect();
    (0..5).for_each(|y| {
        (0..n * 4 - 1).for_each(|x| print!("{}", qwq[x][y]));
        println!("")
    });
}
fn print_scan(k: [i32; 4]) -> Vec<Vec<char>> {
    k.iter()
        .map(|&check| scan_check(check).chars().collect::<Vec<char>>())
        .collect::<Vec<Vec<char>>>()
}
fn scan_check(mut cc: i32) -> String {
    (0..5).fold(String::new(), |x, _| {
        let r = cc % 2 == 0;
        cc >>= 1;
        x + if r { "." } else { "X" }
    })
}
