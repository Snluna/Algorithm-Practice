/*****************************************************
 * Problem: CodeForces-908A
 * Author: _thz
 * Date: Oct 1 2021
 ****************************************************/
#include <cstdio>
#include <cstring>

const int L = 55;

char s[L];

int main() {
  scanf("%s", s);
  int len = strlen(s);
  int sum = 0;
  for (int i = 0; i < len; i++) {
    switch (s[i]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case '1':
      case '3':
      case '5':
      case '7':
      case '9':
        sum++;
        break;
      default:
        break;
    }
  }

  printf("%d\n", sum);

  return 0;
}