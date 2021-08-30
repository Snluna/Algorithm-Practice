/*****************************************************
 * Problem: ABC170B
 * Author: _thz
 * Date: Aug 31 2021
 ****************************************************/
#include <cstdio>

int main() {
  int x, y;
  scanf("%d%d", &x, &y);
  if (y % 2 == 0 && y >= 2 * x && y <= 4 * x) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}
