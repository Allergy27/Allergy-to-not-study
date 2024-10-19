int SelectMinK(int r[], int low, int high, int k) {
    int s;
    s = Partition(r, low, high);
    if(s == k) return r[s];
    if(s > k)
        return SelectMinK(r, low, s - 1, k);
    else
        return SelectMinK(r, s + 1, high, k);
}
