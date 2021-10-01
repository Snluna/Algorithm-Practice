/*****************************************************
 * Problem: CodeForces-593B
 * Author: _thz
 * Date: Sep 29 2021
 ****************************************************/
#include <cstdio>

#include <algorithm>

typedef long long ll;

const int N = 100005;

struct Line {
  ll y1, y2;
} lines[N];

bool cmp(Line a, Line b) {
  if (a.y1 == b.y1) {
    return a.y2 < b.y2;
  }
  return a.y1 < b.y1;
}

int main() {
  int n;
  scanf("%d", &n);
  ll x1, x2;
  scanf("%lld%lld", &x1, &x2);
  ll k, b;
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld", &k, &b);
    lines[i] = {k * x1 + b, k * x2 + b};
  }
  std::sort(lines, lines + n, cmp);
  bool flag = false;
  for (int i = 1; i < n; i++) {
    if (lines[i - 1].y1 != lines[i].y1 && lines[i - 1].y2 > lines[i].y2) {
      flag = true;
      break;
    }
  }

  printf("%s\n", flag ? "Yes" : "No");

  return 0;
}