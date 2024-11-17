//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace luogu/p2615.rs
//@data      2023/12/20 10:19:50
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    let mut qwq = vec![vec![0; n]; n];
    qwq[0][n / 2] = 1;
    let mut pos = vec![0, n / 2];
    for k in 2..=(n * n) as i32 {
        if pos[0] == 0 && pos[1] != n - 1 { //1
            pos = vec![n - 1, pos[1] + 1];
            qwq[pos[0]][pos[1]] = k;
        } else if pos[0] != 0 && pos[1] == n - 1 { //2
            pos = vec![pos[0] - 1, 0];
            qwq[pos[0]][pos[1]] = k;
        } else if pos[0] == 0 && pos[1] == n - 1 { //3
            pos = vec![pos[0] + 1, pos[1]];
            qwq[pos[0]][pos[1]] = k;
        } else if pos[0] != 0 && pos[1] != n - 1 { //4
            if qwq[pos[0] - 1][pos[1] + 1] == 0 {
                pos = vec![pos[0] - 1, pos[1] + 1];
                qwq[pos[0]][pos[1]] = k;
            } else {
                pos = vec![pos[0] + 1, pos[1]];
                qwq[pos[0]][pos[1]] = k;
            }
        }
    }
    (0..n).for_each(|x| {
        (0..n).for_each(|y| print!("{} ", qwq[x][y]));
        println!()
    })
}
