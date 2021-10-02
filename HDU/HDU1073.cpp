/*****************************************************
 * Problem: HDU 1073
 * Author: _thz
 * Date: Oct 2 2021
 ****************************************************/
#include <iostream>
#include <string>

int main() {
  int T;
  std::cin >> T;
  std::string s1, S1, s2, S2, _s;
  while (T--) {
    s1.clear();
    s2.clear();
    S1.clear();
    S2.clear();
    for (int i = 0;; i++) {
      std::getline(std::cin, _s);
      if (_s == "END") {
        break;
      }
      _s += '\n';
      s1.append(_s);
    }

    for (int i = 0;; i++) {
      std::getline(std::cin, _s);
      if (_s == "END") {
        break;
      }
      _s += '\n';
      s2.append(_s);
    }
    if (s1 == s2) {
      std::cout << "Accepted" << std::endl;
    } else {
      int l1 = s1.size();
      int l2 = s2.size();
      for (int i = 0; i < l1; i++) {
        if (s1[i] != '\n' && s1[i] != '\t' && s1[i] != ' ') {
          S1 += s1[i];
        }
      }
      for (int i = 0; i < l2; i++) {
        if (s2[i] != '\n' && s2[i] != '\t' && s2[i] != ' ') {
          S2 += s2[i];
        }
      }
      if (S1 == S2) {
        std::cout << "Presentation Error" << std::endl;
      } else {
        std::cout << "Wrong Answer" << std::endl;
      }
    }
  }

  return 0;
}