/*****************************************************
 * Problem: POJ1723
 * Author: _thz
 * Date: Aug 29 2021
 ****************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>

const int N = 10010;

int x[N], y[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", x + i, y + i);
  }

  int moves = 0;
  int k = n / 2;
  std::nth_element(y, y + k, y + n);
  for (int i = 0; i < n; i++) {
    moves += abs(y[i] - y[k]);
  }

  std::sort(x, x + n);
  for (int i = 0; i < n; i++) {
    x[i] -= i;
  }
  std::nth_element(x, x + k, x + n);
  for (int i = 0; i < n; i++) {
    moves += abs(x[i] - x[k]);
  }

  printf("%d\n", moves);

  return 0;
}
