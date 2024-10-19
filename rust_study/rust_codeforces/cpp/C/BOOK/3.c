typedef struct {
    int pivot, high;
}ElemType;
void Quicksort(int r[], int n) {
    ElemType S[n];
    int top = -1, low = 0, high = n - 1, i;
    while(low < high || top != -1) {
        while(low < high) {
            i = Partition(r, low, high);
            S[++top].pivot = i; S[top].high = high;
            high = i - 1;
        }
        if(top != -1) {
            i = S[top].pivot; low = i + 1; high = S[top--].high;
        }
    }
}