#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define N 100001
typedef struct Candidate {
  int score;
  char code[10];
}
Candidate;
int n;
Candidate * a[N];
void input() {
  char code[11];
  n = 0;
  while (1) {
    scanf("%s", code);
    if (strcmp(code, "#") == 0) break;
    int score;
    scanf("%d", & score);
    n++;
    a[n] = (Candidate * ) malloc(sizeof(Candidate));
    a[n] -> score = score;
    strcpy(a[n] -> code, code);
  }
}
void swap(int i, int j) {
  Candidate * t = a[i];
  a[i] = a[j];
  a[j] = t;
}
void heapify(int i, int n) {
  int L = 2 * i;
  int R = 2 * i + 1;
  int minIdx = i;
  if (L <= n && a[L] -> score < a[minIdx] -> score) minIdx = L;
  if (R <= n && a[R] -> score < a[minIdx] -> score) minIdx = R;
  if (minIdx != i) {
    swap(i, minIdx);
    heapify(minIdx, n);
  }
}
void buildHeap() {
  for (int i = n / 2; i >= 1; i--) heapify(i, n);
}
void sort() {
  buildHeap();
  for (int i = n; i >= 2; i--) {
    swap(1, i);
    heapify(1, i - 1);
  }
}
void print() {
  for (int i = 1; i <= n; i++) {
    printf("%s %d\n", a[i] -> code, a[i] -> score);
  }
}
int main() {
  input();
  sort();
  print();
  return 0;
}
