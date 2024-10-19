pub fn valid_sequence(word1: String, word2: String) -> Vec<i32> {
    let w1 = word1
        .chars()
        .map(|c| (c as u8 - b'a') as usize)
        .collect::<Vec<_>>();
    let w2 = word2
        .chars()
        .map(|c| (c as u8 - b'a') as usize)
        .collect::<Vec<_>>();
    let mut need = vec![w1.len() + 1];
    let mut at = w1.len();
    for i in (0..w2.len()).rev() {
        while at > 0 && w1[at - 1] != w2[i] {
            at -= 1;
        }
        need.push(at);
        at = at.saturating_sub(1);
    }
    need.reverse();
    let mut ans = Vec::new();
    let mut can = 0;
    let mut used = false;
    for i in 0..w2.len() {
        if can == w1.len() {
            return vec![];
        }
        if w1[can] == w2[i] {
            ans.push(can as i32);
            can += 1;
            continue;
        }
        if !used && can + 1 < need[i + 1] {
            ans.push(can as i32);
            can += 1;
            used = true;
            continue;
        }
        let mut found = false;
        while can < w1.len() {
            if w1[can] == w2[i] {
                ans.push(can as i32);
                found = true;
                break;
            }
            can += 1;
        }
        if !found {
            return vec![];
        }
        can += 1;
    }
    ans
}

fn main(){

}