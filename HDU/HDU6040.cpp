/*****************************************************
 * Problem: HDU6040
 * Author: _thz
 * Date: Sep 26 2021
 ****************************************************/
#include <cstdio>
#include <cstring>

#include <algorithm>

const int maxm = 105;
const int maxn = 1e7 + 5;

unsigned ratings[maxn];
unsigned ans[maxm];

struct Hint {
  int num;
  int p;
} hints[maxm];

unsigned x, y, z;
unsigned rng61() {
  unsigned t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  return z;
}

bool cmp(Hint a, Hint b) {
  return a.num < b.num;
}

int main() {
  int n, m, a, b, c;
  int kcase = 0;
  while (scanf("%d%d%d%d%d", &n, &m, &a, &b, &c) != EOF) {
    x = a;
    y = b;
    z = c;
    for (int i = 0; i < m; i++) {
      scanf("%d", &hints[i].num);
      hints[i].p = i;
    }
    for (int i = 0; i < n; i++) {
      ratings[i] = rng61();
    }
    std::sort(hints, hints + m, cmp);
    hints[m].num = n;
    for (int i = m - 1; i >= 0; i--) {
      std::nth_element(ratings, ratings + hints[i].num, ratings + hints[i + 1].num);
      ans[hints[i].p] = ratings[hints[i].num];
    }

    printf("Case #%d:", ++kcase);
    for (int i = 0; i < m; i++) {
      printf(" %u", ans[i]);
    }
    printf("\n");
  }

  return 0;
}