/*****************************************************
 * Problem: CF558A
 * Author: _thz
 * Date: Aug 29 2021
 ****************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

const int N = 105;

struct ap {
  int x;
  int a;
} aps[N];

int main() {
  auto cmp = [](ap a, ap b) -> bool { return a.x < b.x; };

  int n;
  scanf("%d", &n);
  int xpos = 0, xneg = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &aps[i].x, &aps[i].a);
    (aps[i].x > 0 ? xpos : xneg) += 1;
  }

  std::sort(aps, aps + n, cmp);

  int sum = 0;
  if (xpos == xneg) {
    for (int i = 0; i < n; i++) {
      sum += aps[i].a;
    }
  } else if (xpos > xneg) {
    for (int i = 0; i < 2 * xneg + 1; i++) {
      sum += aps[i].a;
    }
  } else {
    for (int i = n - 1; i >= n - 1 - 2 * xpos; i--) {
      sum += aps[i].a;
    }
  }
  printf("%d\n", sum);

  return 0;
}
