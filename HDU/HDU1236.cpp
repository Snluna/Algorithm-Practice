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

#define DEBUG

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second > b.second;
}

int main()
{
  #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  #endif // DEBUG

  int N, M, G;
  while (scanf("%d", &N) && N) {
    scanf("%d%d", &M, &G);
    int score;
    vector<int> scores;
    for (int i = 0; i < M; i++) {
      scanf("%d", &score);
      scores.push_back(score);
    }
    vector<pair<string, int>> grades;
    string sid;
    int num, qid;
    int n = 0;
    for (int i = 0; i < N; i++) {
      int grade = 0;
      cin >> sid;
      scanf("%d", &num);
      for (int j = 0; j < num; j++) {
        scanf("%d", &qid);
        grade += scores[qid - 1];
      }
      if (grade >= G) {
        n++;
        grades.push_back({sid, grade});
      }
    }

    sort(grades.begin(), grades.end(), cmp);

    if (N > 0) {
      printf("%d\n", n);
      for (auto it = grades.begin(); it != grades.end(); it++) {
        cout << it->first << " " << it->second << endl;
      }
    }
  }

  return 0;
}
