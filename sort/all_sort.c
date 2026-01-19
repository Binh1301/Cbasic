#checkexist
#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 200003  // số nguyên tố

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* hashTable[HASH_SIZE];

int hash(int x) {
    if (x < 0) x = -x;
    return x % HASH_SIZE;
}

int exists(int x) {
    int h = hash(x);
    Node* cur = hashTable[h];
    while (cur) {
        if (cur->key == x) return 1;
        cur = cur->next;
    }
    return 0;
}

void insert(int x) {
    int h = hash(x);
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = x;
    node->next = hashTable[h];
    hashTable[h] = node;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        if (exists(x)) {
            printf("1\n");
        } else {
            printf("0\n");
            insert(x);
        }
    }
    return 0;
}
#check
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
#heapify
#include <stdio.h>
#include <string.h>

char arr[500][81];

void heapify(int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && strcmp(arr[l], arr[largest]) > 0)
        largest = l;

    if (r < n && strcmp(arr[r], arr[largest]) > 0)
        largest = r;

    if (largest != i) {
        char tmp[81];
        strcpy(tmp, arr[i]);
        strcpy(arr[i], arr[largest]);
        strcpy(arr[largest], tmp);

        heapify(n, largest);
    }
}

void heapSort(int n){

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    
    for (int i = n - 1; i > 0; i--) {
        char tmp[81];
        strcpy(tmp, arr[0]);
        strcpy(arr[0], arr[i]);
        strcpy(arr[i], tmp);

        heapify(i, 0);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%s", arr[i]);

    heapSort(n);

    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);

    return 0;
}

#1
#include <stdio.h>
void quicksort(int a[], int l, int r){
    int i = l;
    int j = r;
    int p = a[ (l + r) / 2];
    while( i <= j){
        while(a[i] < p) i++;
        while(a[j] > p) j--;
        if( i <= j){
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }
    if(l < j) quicksort(a,l,j);
    if(i < r) quicksort(a,i,r);

}
int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    int a[1000];
    int x[1000];
    for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            x[i] = a[i];}


    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++){
        if(a[i] != x[i]) cnt++;}
    printf("%d", cnt);
    return 0;
}
#qs
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void*a,const void*b){
    return *(int*)a - *(int*)b;
}
int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    int a[1000];
    int x[1000];
    for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            x[i] = a[i];}

    qsort(a,n,sizeof(int), cmp);
    for (int i = 0; i < n; i++){
        if(a[i] != x[i]) cnt++;}
    printf("%d", cnt);
    return 0;
}

#quick
#include <stdio.h>


void quicksort(int a[], int l, int r){
    int i = l;
    int j = r;
    int p = a[( l + r ) / 2];
    while(i <= j){
        while(a[i] < p) i++;
        while(a[j] > p) j--;
        if( i <= j){
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if(l < j) quicksort(a,l,j);
    if(i < r) quicksort(a,i,r);
}
int main() {
    int n;
    scanf("%d", &n);
    int a[1000];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
#quicksort\
#include <stdio.h>
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int a[], int l, int r){
    int pivot = a[r];
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(a[j] < pivot){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[r]);
    return i + 1;
}

void quicksort(int a[], int l,int r){
    if(l < r){
        int p = partition(a,l,r);
        quicksort(a,l,p-1);
        quicksort(a,p+1,r);
    }
}
int main(){
    int a[] = {5, 3, 8, 4, 2, 7, 1, 10};
    int n = sizeof(a)/sizeof(a[0]);
    quicksort(a, 0, n - 1);
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
#sort_candi
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char code[11];
    int score;
} candidate;

candidate a[100000];
int n = 0;

int cmp(const void *x, const void *y) {
    const candidate *a = x;
    const candidate *b = y;
    if (a->score < b->score) return 1;
    if (a->score > b->score) return -1;
    return 0;
}

int main() {
    char tmp[20];

    while (1) {
        if (scanf("%s", tmp) != 1) break;
        if (strcmp(tmp, "#") == 0) break;

        strcpy(a[n].code, tmp);
        scanf("%d", &a[n].score);
        n++;
    }

    qsort(a, n, sizeof(candidate), cmp);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", a[i].code, a[i].score);
    }

    return 0;
}
#sort
#include <stdio.h>

int exist[1000001];

int main() {
    int n, m, x;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        exist[x] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        if (exist[x] == 1) {
            cnt++;
            exist[x] = 2;
        }
    }

    printf("%d", cnt);
    return 0;
}
#sort1
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
#sortcandicate
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
#sortstring
#include <stdio.h>
#include <string.h>

#define MAXN 100000
#define MAXLEN 105

char s[MAXN][MAXLEN];

void swap(char a[], char b[]) {
    char temp[MAXLEN];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void quickSort(int left, int right) {
    if (left >= right) return;

    int i = left, j = right;
    char pivot[MAXLEN];
    strcpy(pivot, s[(left + right) / 2]);

    while (i <= j) {
        while (strcmp(s[i], pivot) < 0) i++;
        while (strcmp(s[j], pivot) > 0) j--;

        if (i <= j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    if (left < j) quickSort(left, j);
    if (i < right) quickSort(i, right);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    quickSort(0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%s\n", s[i]);
    }

    return 0;
}
#tongcheck
#include <stdio.h>

#define N 1000001
int a[N];
int n, Q;
void input() {
  scanf("%d%d", & n, & Q);
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
  int cnt = 0;
  for (int i = 1; i <= n - 1; i++) {
    int idx = bSearch(i + 1, n, Q - a[i]);
    if (idx > -1) cnt = cnt + 1;
  }
  printf("%d", cnt);
  return 0;
}
#sapxepcackitu
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int cmp(const void* a, const void* b)
{
    return strcmp((const char*)a, (const char*)b);
}

int main()
{
    int n;
    scanf("%d", &n);
    char arr[n][100];
    for (int i = 0; i<n; i++)
    {
        scanf("%s", arr[i]);
    }
    qsort(arr, n, sizeof(arr[0]), cmp);
    for (int i = 0; i<n; i++)
    {
        printf("%s\n", arr[i]);
    }
    return 0;
}
#sapxepcacbanghi
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[11];
    int grade;
} student;

int cmp(const void* a, const void* b)
{
    const student *x = (const student *)a;
    const student *y = (const student *)b;
    return (int*)y->grade - (int*)x->grade;
}

int main()
{
    int capacity = 2;          
    int n = 0;               
    student *arr = malloc(capacity * sizeof(student));

    while (1) {
        char temp_id[11];
        int temp_grade;

        scanf("%s", temp_id);

        if (strcmp(temp_id, "#") == 0)
            break;

        scanf("%d", &temp_grade);

        if (n == capacity) {
            capacity *= 2;
            arr = realloc(arr, capacity * sizeof(student));
        }

        strcpy(arr[n].id, temp_id);
        arr[n].grade = temp_grade;
        n++;
    }

    qsort(arr, n, sizeof(student), cmp);

    for (int i = 0; i < n; i++)
        printf("%s %d\n", arr[i].id, arr[i].grade);

    free(arr);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char id[11];
    int grade;
} student;

int cmp(const void* a, const void* b)
{
    const student *x = (const student *)a;
    const student *y = (const student *)b;
    return strcmp(x->id, y->id); 
}

int main()
{
    int n;
    scanf("%d", &n);

    student arr[n];

    for (int i = 0; i < n; i++)
        scanf("%s %d", arr[i].id, &arr[i].grade);

    qsort(arr, n, sizeof(student), cmp);

    for (int i = 0; i < n; i++)
        printf("%s %d\n", arr[i].id, arr[i].grade);

    return 0;
}
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

int cmp (const void* ptr1, const void* ptr2)
{
    int* x = (int*)ptr1;
    int* y = (int*)ptr2;
    return *x - *y;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int dim;

int cmp(const void* a, const void* b)
{
    const int *v1 = (const int *)a;
    const int *v2 = (const int *)b;
    for (int i = 0; i < dim; i++) 
    {
        if (v1[i] != v2[i])
            return v1[i] - v2[i];
    }
    return 0;
}


int main()
{
    int n;
    scanf("%d%d", &n, &dim);
    int arr[n][dim];
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<dim; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    qsort(arr, n, sizeof(arr[0]), cmp);

    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<dim; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
#demtutrongcau
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char text[100];
    int count;
} Word;

int main()
{
    char line[512];
    Word tu[1000];
    int n = 0;

    while (fgets(line, sizeof(line), stdin) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';
        int len = strlen(line);

        for (int i = 0; i < len; i++)
        {
            if (!isalpha(line[i]))
                line[i] = ' ';
            else
                line[i] = tolower(line[i]);
        }


        char* token = strtok(line, " ");
        while (token != NULL)
        {
            int found = 0;
            for (int i = 0; i < n; i++)
            {
                if (strcmp(tu[i].text, token) == 0)
                {
                    tu[i].count++;
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                strcpy(tu[n].text, token);
                tu[n].count = 1;
                n++;
            }

            token = strtok(NULL, " ");
        }
    }


    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(tu[i].text, tu[j].text) > 0)
            {
                Word tmp = tu[i];
                tu[i] = tu[j];
                tu[j] = tmp;
            }

    for (int i = 0; i < n; i++)
        printf("%s %d\n", tu[i].text, tu[i].count);

    return 0;
}
#sapxepcacsinhvien
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 64

int cmpStr(const void* a, const void* b) 
{
    return strcmp((char*)a, (char*)b);
}

typedef struct in4
{
    char ten[MAX];
    char mssv[MAX];
}in4;

in4 ds[1000];
int n = 0;

int cmpMSSV(const void* a, const void* b) 
{
    in4* x = (in4*)a;
    in4* y = (in4*)b;
    return strcmp(x->mssv, y->mssv);
}


void nhapchuoi()
{
    char line[256];
    while (1)
    {
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, "end.") == 0) break;
        char* sv = strtok(line, ";");
        while (sv != NULL) 
        {
            char* comma = strchr(sv, ',');
            if (comma != NULL) 
            {
                *comma = '\0';
                strcpy(ds[n].ten, sv);
                strcpy(ds[n].mssv, comma + 1);
                n++;
            }
            sv = strtok(NULL, ";");
        }
    }
}

char* layTen(char* hoten) 
{
    char* lastSpace = strrchr(hoten, ' ');
    if (lastSpace == NULL)
        return hoten;        
    return lastSpace + 1;    
}


void timTen() 
{
    char key[MAX];

    while (1) 
    {
        fgets(key, sizeof(key), stdin);
        key[strcspn(key, "\n")] = '\0';

        if (strcmp(key, "end.") == 0) break;

        int found = 0;
        for (int i = 0; i < n; i++) 
        {
            char* ten = layTen(ds[i].ten);
            if (strcmp(ten, key) == 0) 
            {
                printf("%s\n", ds[i].mssv);
                found = 1;
            }
        }
        if (!found)
            printf("Khong thay\n");
    }
}



int main() 
{
    nhapchuoi();
    timTen();
    qsort(ds, n, sizeof(in4), cmpMSSV);
    for (int i = 0; i < n; i++) 
    {
        printf("%s", ds[i].mssv);
        if (i < n - 1) printf(",");
    }
    return 0;
}

