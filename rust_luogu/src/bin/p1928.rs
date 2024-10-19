//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p1928.rs
//@data      2024/01/20 13:14:15
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
    let t = cin().chars().collect::<Vec<char>>();
    read(&t, 0).1.chars().for_each(|x| print!("{}", x))
}
fn read(s: &Vec<char>, mut l: usize) -> (usize, String) {
    let mut ans = String::new();
    while l < s.len() {
        let x = s[l];
        l += 1;
        if x == '[' {
            let mut n = (s[l] as u8 - b'0') as i32;
            l += 1;
            if '0' <= s[l] && s[l] <= '9' {
                n = n * 10 + (s[l] as u8 - b'0') as i32;
                l += 1
            }
            let (p, s1) = read(s, l);
            l = p;
            for _ in 0..n {
                ans += &s1
            }
        } else if x == ']' {
            return (l, ans);
        } else {
            ans.push(x);
        }
    }
    (l, ans)
}
