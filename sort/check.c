#include <stdio.h>

#define N 100001
int a[N];
int n;
void input() {
  scanf("%d", & n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", & a[i]);
  }
}
void swap(int i, int j) {
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}
void heapify(int i, int n) {
  int L = 2 * i;
  int R = 2 * i + 1;
  int maxIdx = i;
  if (L <= n && a[maxIdx] < a[L]) maxIdx = L;
  if (R <= n && a[maxIdx] < a[R]) maxIdx = R;
  if (maxIdx != i) {
    swap(i, maxIdx);
    heapify(maxIdx, n);
  }
}
void buildHeap() {
  for (int i = n / 2; i >= 1; i--) heapify(i, n);
}
void heapSort() {
  buildHeap();
  for (int i = n; i >= 2; i--) {
    swap(1, i);
    heapify(1, i - 1);
  }
}
int bSearch(int i, int j, int k) {
  if (i > j) return -1;
  if (i == j) {
    if (a[i] == k) return i;
    else return -1;
  }
  int m = (i + j) / 2;
  if (a[m] == k) return m;
  if (a[m] < k) return bSearch(m + 1, j, k);
  else return bSearch(i, m - 1, k);
}
int main() {
  input();
  heapSort();
  char cmd[30];
  while (1) {
    scanf("%s", cmd);
    if (strcmp(cmd, "#") == 0) break;
    else if (strcmp(cmd, "check") == 0) {
      int k;
      scanf("%d", & k);
      int i = bSearch(1, n, k);
      if (i > 0) i = 1;
      else i = 0;
      printf("%d\n", i);
    }
  }
  return 0;
}