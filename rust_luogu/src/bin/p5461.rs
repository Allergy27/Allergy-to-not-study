//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace Prectice_Contest/p5461.rs
//@data      2024/10/27 20:02:15
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
    let n = cin().parse::<usize>().unwrap();
    if n == 0 {
        println!("0");
        return;
    }
    let n = 1 << n;
    let mut grid = vec![vec![1; n]; n];
    let mut dfs = |x: (usize, usize), y: (usize, usize)| {
        let mut que = std::collections::VecDeque::<((usize, usize), (usize, usize))>::new();
        que.push_back((x, y));
        // let mut time = 20;
        while !que.is_empty() {
            // time -= 1;
            // if time == 0 {
            //     break;
            // }
            let (x, y) = que.pop_front().unwrap();
            if x.0.abs_diff(y.0) == 2 && x.1.abs_diff(y.1) == 2 {
                grid[x.0][x.1] = 0;
                continue;
            }
            for row in grid.iter_mut().take((y.0 + x.0) >> 1).skip(x.0) {
                for cell in row.iter_mut().take((y.1 + x.1) >> 1).skip(x.1) {
                    *cell = 0;
                }
            }
            que.push_back((((x.0 + y.0) >> 1, (x.1 + y.1) >> 1), y));
            que.push_back((((x.0 + y.0) >> 1, x.1), (y.0, (x.1 + y.1) >> 1)));
            que.push_back(((x.0, (x.1 + y.1) >> 1), ((x.0 + y.0) >> 1, y.1)));
        }
    };
    dfs((0, 0), (n, n));
    for row in grid.iter() {
        for cell in row.iter() {
            print!("{} ", cell);
        }
        println!();
    }
}
