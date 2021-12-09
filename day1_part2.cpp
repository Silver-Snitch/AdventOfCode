#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int first, second, third;
  cin >> first >> second >> third;
  int next;
  int answer = 0;
  while (cin >> next) {
    answer += (next > first);
    first = second;
    second = third;
    third = next;
  }
  cout << answer;

  return 0;
}
