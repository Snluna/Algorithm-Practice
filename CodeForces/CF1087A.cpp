/*****************************************************
 * Problem: CF1087A
 * Author: _thz
 * Date: Aug 28 2021
 ****************************************************/
#include <cstdio>
#include <cstring>

#define DEBUG

const int N = 55;

char s[N];

int main()
{
  #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  #endif // DEBUG

  scanf("%s", s);
  int len = strlen(s);
  int p = (len - 1) / 2;

  printf("%c", s[p]);
  for (int i = 1; i < (len + 1) / 2; i++) {
    printf("%c%c", s[p + i], s[p - i]);
  }
  if (!(len & 1)) {
    printf("%c", s[len - 1]);
  }

  return 0;
}
