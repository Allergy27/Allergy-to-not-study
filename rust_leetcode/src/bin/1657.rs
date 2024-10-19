fn main() {
    let (mut qwq, mut qaq) = (vec![0; 26], vec![0; 26]);
    let word1 = String::from("aba");
    let word2 = String::from("bab");
    if word1.len() != word2.len() {
        return;
    }
    word1
        .chars()
        .for_each(|x| qwq[x as usize - b'a' as usize] += 1);
    word2
        .chars()
        .for_each(|x| qaq[x as usize - b'a' as usize] += 1);
    for i in 0..26 {
        if (qwq[i] != 0) ^ (qaq[i] != 0) {
            return;
        }
    }
    qwq.sort_unstable();
    qaq.sort_unstable();
}
