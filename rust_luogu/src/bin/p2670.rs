//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p2670.rs
//@data      2024/10/28 01:46:53
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
    let (n, m) = cin().split_whitespace().fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    let mut a = vec![Vec::new(); n];
    for row in &mut a {
        *row = cin().chars().collect::<Vec<_>>();
    }
    for i in 0..n {
        for j in 0..m {
            print!(
                "{}",
                if a[i][j] != '*' {
                    [
                        (-1, -1),
                        (-1, 0),
                        (-1, 1),
                        (0, -1),
                        (1, -1),
                        (0, 1),
                        (1, 0),
                        (1, 1),
                    ]
                    .iter()
                    .fold(0, |ans, (x, y)| {
                        let (x, y) = (i as i32 + x, j as i32 + y);
                        ans + if x >= 0
                            && x < n as i32
                            && y >= 0
                            && y < m as i32
                            && a[x as usize][y as usize] == '*'
                        {
                            1
                        } else {
                            0
                        }
                    })
                    .to_string()
                } else {
                    "*".to_string()
                }
            );
        }
        println!()
    }
}
