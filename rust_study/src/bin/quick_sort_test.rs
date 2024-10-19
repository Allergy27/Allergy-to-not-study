//@author    Allergy
//@email     Allergy527@gmail.com
//@workspace src\bin\quick_sort.rs
//@data      2023/12/12 20:00:37
use rand::Rng;
use std::time::Instant;
fn main() {
    let mut rng = rand::thread_rng();
    let mut qwq: Vec<i32> = (0..1000000)
        .map(|_| rng.gen_range(0..100000000))
        .collect();
    let t = Instant::now();
    // qsort(&mut qwq);
    qwq.sort_unstable();
    println!("{}", t.elapsed().as_millis());
}
fn qsort<T: Ord + Clone + Copy>(xs: &mut [T]) -> Vec<T> {
    if xs.len() <= 1 {
        return xs.to_vec();
    }
    let small = qsort(
        &mut xs[1..]
            .iter()
            .filter_map(|x| if x <= &xs[0] { Some(*x) } else { None })
            .collect::<Vec<_>>(),
    );
    let big = qsort(
        &mut xs[1..]
            .iter()
            .filter_map(|x| if x > &xs[0] { Some(*x) } else { None })
            .collect::<Vec<_>>(),
    );
    small.into_iter().chain([xs[0]]).chain(big).collect()
}
