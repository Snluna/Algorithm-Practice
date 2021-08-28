/*****************************************************
 * Problem: HDU5427
 * Author: _thz
 * Date: Aug 20 2021
 ****************************************************/
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <vector>

const int N = 120;
const int L = 110;

struct Person
{
  char name[L];
  int birth_year;
}people[N];

bool cmp(Person a, Person b) {
  return a.birth_year > b.birth_year;
}

int main()
{
  int T;
  scanf("%d", &T);
  int n;
  while (T--) {
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
      gets(people[i].name);
      people[i].birth_year = 0;
      int len = strlen(people[i].name);
      for (int j = len - 4; j <= len - 1; j++) {
        people[i].birth_year = people[i].birth_year * 10 + (people[i].name)[j] - '0';
      }
      (people[i].name)[len - 5] = '\0';
    }
    std::sort(people, people + n, cmp);
    for (int i = 0; i < n; i++) {
      printf("%s\n", people[i].name);
    }
  }

  return 0;
}
