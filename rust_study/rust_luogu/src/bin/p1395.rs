//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\p1395.rs
//@data      2023/12/13 14:08:21
fn main() {
    let t = 1;
    //let mut input = String::new();std::io::stdin().read_line(&mut input).unwrap();let t:i32=input.parse().unwrap();
    (0..t).for_each(|_| solve());
}
fn solve() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    let mut qwq: Vec<Vec<usize>> = vec![vec![]; n + 1];
    for _ in 0..n - 1 {
        //读输入
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut input = input.split_whitespace();
        let (a, b): (usize, usize) = (
            input.next().unwrap().parse().unwrap(),
            input.next().unwrap().parse().unwrap(),
        );
        qwq[b].push(a);
        qwq[a].push(b);
    }
    let x = dfs(&qwq, 1, 1, n).2 .1; //找重心
    println!("{} {}", x, bfs(&qwq, x, x, 0).1);
}

fn dfs(t: &Vec<Vec<usize>>, node: usize, fa: usize, n: usize) -> (usize, usize, (usize, usize)) {
    let mut ans = (1, 1, (n, 0)); //(子树和，最大子树，最小节点)
    for &son in t[node].iter() {
        if son != fa {
            let k = dfs(t, son, node, n); //子树
            ans.0 += k.0;
            ans.1 = ans.1.max(k.0);
            if ans.2 .0 > k.2 .0 {
                ans.2 = k.2;
            }
        }
    }
    ans.1 = ans.1.max(n - ans.0);
    if ans.1 < ans.2 .0 {
        ans.2 = (ans.1, node);
    } else if ans.1 == ans.2 .0 {
        ans.2 .1 = node.min(ans.2 .1);
    }
    ans
}
fn bfs(t: &Vec<Vec<usize>>, node: usize, fa: usize, dth: usize) -> (usize, usize) {
    let mut ans = (dth, 0); //深度，节点数
    for &son in t[node].iter() {
        if son != fa {
            let k = bfs(t, son, node, dth + 1);
            ans.1 += k.0 + k.1;
        }
    }
    ans
}
