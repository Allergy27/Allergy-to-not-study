#include <stdio.h>

void StraightSort(int r[], int n) {
    int i, j, low, high, mid, temp;
    for(i = 1; i < n; ++i) {
        low = 0;
        high = i - 1;
        while(low <= high) {
            mid = (low + high) / 2;
            if(r[i] < r[mid]) high = mid - 1;
            else low = mid + 1;
        }
        temp = r[i];
        for(j = i - 1; j >= high + 1; --j) r[j + 1] = r[j];
        r[high + 1] = temp;
    }
}
void print(int r[], int n) {
    int i;
    for(i = 0; i < n; ++i) {
        printf("%d ", r[i]);
    }
}
int main() {
    int r[10] = { 1, 10, 2, 9, 3, 8, 4, 7, 5, 6 };
    StraightSort(r, 10);
    print(r, 10);
    return 0;
}