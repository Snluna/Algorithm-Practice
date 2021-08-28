/*****************************************************
 * Problem: HDU5414
 * Author: _thz
 * Date: Aug 28 2021
 ****************************************************/
#include <cstdio>
#include <cstring>

#include <algorithm>

const int L = 100010;

char s[L], t[L];

int main()
{
  int T;
  scanf("%d", &T);
  
  bool flag;
  int lens, lent, i, j;
  while (T--) {
    flag = true;

    scanf("%s", s);
    scanf("%s", t);
    lens = strlen(s);
    lent = strlen(t);

    i = j = 0;
    while (i < lens && j <lent) {
      if (s[i] == t[j]) {
        i++;
      }
      j++;
    }
    if (i < lens) {
      flag = false;
    }

    j = 1;
    while (t[j] == t[j - 1] && j < lent) {
      j++;
    }
    for (i = 0; i < j; i++) {
      if (s[i] != t[0]) {
        flag = false;
        break;
      }
    }

    printf("%s\n", flag ? "Yes" : "No");
  }

  return 0;
}
