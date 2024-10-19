//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\quick_sort.rs
//@data      2023/12/12 20:00:37
fn main() {
    let mut qwq: Vec<i128> = vec![96, 86, 68, 67, 46, 54, 4, 21, 34, 15, 32, 62];
    qwq = qsort(&mut qwq);
    for i in qwq {
        println!("{}", i)
    }
}
fn qsort<T: Ord + Clone + Copy>(xs: &mut Vec<T>) -> Vec<T> {
    if xs.len() <= 1 { return xs.to_vec(); }
    let small = qsort(&mut xs[1..].into_iter().filter_map(|x|if x <= &xs[0]{ Some(*x) }else{ None }).collect());
    let big = qsort(&mut xs[1..].into_iter().filter_map(|x|if x > &xs[0]{ Some(*x) }else{ None }).collect());
    small.into_iter().chain([xs[0]].into_iter()).chain(big.into_iter()).collect()
}
