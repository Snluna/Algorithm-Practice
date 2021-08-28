/*****************************************************
 * Problem: HDU1236
 * Author: _thz
 * Date: Aug 16 2021
 ****************************************************/
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second > b.second;
}

int main()
{
  int n, m, g;
  while (scanf("%d", &n) && n) {
    scanf("%d%d", &m, &g);
    int score;
    vector<int> scores;
    for (int i = 0; i < m; i++) {
      scanf("%d", &score);
      scores.push_back(score);
    }
    vector<pair<string, int>> grades;
    string sid;
    int sum, qid;
    int num = 0;
    for (int i = 0; i < n; i++) {
      int grade = 0;
      cin >> sid;
      scanf("%d", &sum);
      for (int j = 0; j < sum; j++) {
        scanf("%d", &qid);
        grade += scores[qid - 1];
      }
      if (grade >= g) {
        num++;
        grades.push_back({sid, grade});
      }
    }

    sort(grades.begin(), grades.end(), cmp);

    if (n > 0) {
      printf("%d\n", n);
      for (auto it = grades.begin(); it != grades.end(); it++) {
        cout << it->first << " " << it->second << endl;
      }
    }
  }

  return 0;
}
