/*****************************************************
 * Problem: HDU4545
 * Author: _thz
 * Date: Aug 19 2021
 ****************************************************/
#include <cstdio>
#include <cstring>

const int L = 1005;
const int N = 30;

char sa[L], sb[L];
int dict[N][N];
int tag[N];

int main() {
  int t;
  scanf("%d", &t);
  int m;
  char da, db;
  for (int kcase = 1; kcase <= t; kcase++) {
    std::memset(sa, '\0', sizeof(sa));
    std::memset(sb, '\0', sizeof(sb));
    std::memset(dict, 0, sizeof(dict));

    scanf("%s", sa);
    scanf("%s", sb);
    int salen = std::strlen(sa);
    int sblen = std::strlen(sb);

    scanf("%d", &m);
    while (m--) {
      getchar();
      scanf("%c %c", &da, &db);
      dict[da - 'a'][db - 'a'] = 1;
    }

    int j = 0;
    bool flag = true;
    for (int i = 0; i < salen; i++) {
      if (j == sblen) {
        break;
      }

      if (sa[i] == sb[j]) {
        j++;
        continue;
      }

      while (sa[i] != sb[j]) {
        if (j == sblen) {
          flag = false;
          break;
        }
        if (dict[sb[j] - 'a'][sa[i] - 'a'] == 1) {
          j++;
          break;
        } else {
          j++;
        }
      }
    }
    printf("Case #%d: %s\n", kcase, flag ? "happy" : "unhappy");
  }

  return 0;
}
