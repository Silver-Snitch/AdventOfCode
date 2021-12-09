#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int curr = -1, answer = 0, next = -1;
  cin >> curr;
  while (cin >> next) {
    answer += (next > curr);
    curr = next;
  }
  cout << answer;

  return 0;
}
