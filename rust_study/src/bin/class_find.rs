//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace study/class_tower.rs
//@data      2024/06/25 10:00:11
fn cin() -> String {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}
use std::collections::VecDeque; //队列bfs
fn main() {
    println!("Please enter the 'n' and 'm' in one line and splite with ' ':");
    let (n, m) = cin()
        .split_whitespace()
        .fold((0, 0), |x, y| (x.1, y.parse::<usize>().unwrap()));
    let mut qwq = vec![vec![1; m + 2]; n + 2]; //迷宫
    let mut queue = VecDeque::new();

    println!("Please enter the labyrinth:");
    for cnt in qwq.iter_mut().skip(1) {
        for (p, q) in cin().split_whitespace().enumerate() {
            cnt[p + 1] = q.parse::<i32>().unwrap(); //输入迷宫部分
        }
    }
    //用闭包包装，实现任意起点终点调用此函数即可解决
    let mut bfs = |start_x: i32, start_y: i32, end_x: usize, end_y: usize| {
        let point = [-1, 0, 1, 0, -1];
        queue.push_back((start_x, start_y, (start_x, start_y)));
        let mut way = vec![vec![(0, 0); m + 2]; n + 2]; //迷宫路径

        while !queue.is_empty() {
            let (x, y, (pre_x, pre_y)) = queue.pop_front().unwrap();
            let (x, y) = (x as usize, y as usize);
            if qwq[x][y] == 0 && way[x][y] == (0, 0) {
                way[x][y] = (pre_x, pre_y);

                //到达终点
                if x == end_x && y == end_y {
                    let (mut p, mut q) = (end_x as i32, end_y as i32);
                    let mut ans = String::new();
                    while (p, q) != (start_x, start_y) {
                        ans = format!("({} {})\n", p, q) + &ans;
                        (p, q) = way[p as usize][q as usize];
                    }
                    println!("({} {})\n{}", p, q, ans);
                    break;
                }

                //转移
                for i in 0..4 {
                    let (x, y) = (x as i32, y as i32);
                    queue.push_back((x + point[i], y + point[i + 1], (x, y)));
                }
            }
        }
    };
    println!("Here is one right route:");
    bfs(1, 1, n, m);
}
