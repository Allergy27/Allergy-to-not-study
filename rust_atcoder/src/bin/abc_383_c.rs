//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace PrecticeContest/abc_383_c.rs
//@data      2024/12/07 20:26:06
#[macro_export]
macro_rules! cin {
    ()=>{{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().to_string()
    }};
    ([char]) => {{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().chars().collect::<Vec<char>>()
    }};
    ([u8]) =>{{
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().bytes().collect::<Vec<u8>>()
    }};
    ([$type:ty;$n:expr]) => {{
        let mut input = String::new();
        let mut s = loop{
            input.clear();
            std::io::stdin().read_line(&mut input).unwrap();
            let s = input.trim();
            if !s.is_empty() {
                break s.split_whitespace();
            }
        };
        let mut arr = Vec::with_capacity($n as usize);
        for _ in 0..$n {
            arr.push((s.next().unwrap()).parse::<$type>().unwrap());
        }
        arr
    }};
    ($type:ty) => {{
        let mut input = String::new();
        let mut s = loop{
            input.clear();
            std::io::stdin().read_line(&mut input).unwrap();
            let s = input.trim();
            if !s.is_empty() {
                break s.split_whitespace();
            }
        };
        (s.next().unwrap()).parse::<$type>().unwrap()
    }};
    ($($type:ty),*) => {{
        let mut input = String::new();
        let mut s = loop{
            input.clear();
            std::io::stdin().read_line(&mut input).unwrap();
            let s = input.trim();
            if !s.is_empty() {
                break s.split_whitespace();
            }
        };
        ($(s.next().unwrap().parse::<$type>().unwrap()),*)
    }}
}
fn main() {
    let t = 1;
    // let t = cin!(i64);
    (0..t).for_each(|_| solve());
}
fn solve() {
    let (h, w, d) = cin!(usize, usize, i64);
    let mut qwq = vec![Vec::new(); h];
    for x in &mut qwq {
        *x = cin!([char]);
    }
    // BFS 队列和访问集合
    let mut que = std::collections::VecDeque::new();
    let mut vis = std::collections::HashSet::new();

    // 寻找所有的加湿器 (H) 位置
    for i in 0..h {
        for j in 0..w {
            if qwq[i][j] == 'H' {
                que.push_back((i, j, 0)); // 加入 (x, y, 距离)
                vis.insert((i, j)); // 标记为已访问
            }
        }
    }

    let way = [(-1, 0), (1, 0), (0, -1), (0, 1)];
    while let Some((x, y, dist)) = que.pop_front() {
        if dist >= d {
            continue;
        }
        for (dx, dy) in &way {
            let nx = x as isize + dx;
            let ny = y as isize + dy;
            if nx >= 0 && ny >= 0 && nx < h as isize && ny < w as isize {
                let nx = nx as usize;
                let ny = ny as usize;
                if qwq[nx][ny] != '#' && !vis.contains(&(nx, ny)) {
                    vis.insert((nx, ny));
                    que.push_back((nx, ny, dist + 1));
                }
            }
        }
    }
    println!("{}", vis.len());
}
