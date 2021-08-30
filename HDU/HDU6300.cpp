/*****************************************************
 * Problem: HDU6300
 * Author: _thz
 * Date: Aug 25 2021
 ****************************************************/
#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 10000;

struct coo {
  int id;
  int x, y;
} coos[3 * N + 1];

int main() {
  auto cmp = [](coo a, coo b) -> bool { return a.x < b.x; };

  int T;
  scanf("%d", &T);
  int n;
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < 3 * n; i++) {
      scanf("%d%d", &coos[i].x, &coos[i].y);
      coos[i].id = i + 1;
    }
    std::sort(coos, coos + 3 * n, cmp);
    for (int i = 0; i < 3 * n; i += 3) {
      printf("%d %d %d\n", coos[i].id, coos[i + 1].id, coos[i + 2].id);
    }
  }

  return 0;
}