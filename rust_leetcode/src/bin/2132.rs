//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace leetcode/2132.rs
//@data      2023/12/14 20:13:32
fn main() {
    let t = 1;
    let qwq: Vec<Vec<i32>> = vec![
        [1, 0, 0, 0].to_vec(),
        [1, 0, 0, 0].to_vec(),
        [1, 0, 0, 0].to_vec(),
        [1, 0, 0, 0].to_vec(),
        [1, 0, 0, 0].to_vec()
    ];
    let (a, b) = (4, 3);
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
   (0..t).for_each(|_| println!("{}", solve(&qwq, a, b)));
}

fn solve(grid: &[Vec<i32>], stamp_height: i32, stamp_width: i32) -> bool {
    let m = grid.len();

    let n = grid[0].len();

    // 1. 计算 grid 的二维前缀和

    let mut s = vec![vec![0; n + 1]; m + 1];

    for (i, row) in grid.iter().enumerate() {
        for (j, &v) in row.iter().enumerate() {
            s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + v;
        }
    }

    // 2. 计算二维差分

    // 为方便第 3 步的计算，在 d 数组的最上面和最左边各加了一行（列），所以下标要 +1

    let mut d = vec![vec![0; n + 2]; m + 2];

    for i2 in stamp_height as usize..=m {
        for j2 in stamp_width as usize..=n {
            let i1 = i2 - stamp_height as usize + 1;

            let j1 = j2 - stamp_width as usize + 1;

            if s[i2][j2] - s[i2][j1 - 1] - s[i1 - 1][j2] + s[i1 - 1][j1 - 1] == 0 {
                d[i1][j1] += 1;

                d[i1][j2 + 1] -= 1;

                d[i2 + 1][j1] -= 1;

                d[i2 + 1][j2 + 1] += 1;
            }
        }
    }

    // 3. 还原二维差分矩阵对应的计数矩阵（原地计算）

    for (i, row) in grid.iter().enumerate() {
        for (j, &v) in row.iter().enumerate() {
            d[i + 1][j + 1] += d[i + 1][j] + d[i][j + 1] - d[i][j];

            if v == 0 && d[i + 1][j + 1] == 0 {
                return false;
            }
        }
    }

    true
}
