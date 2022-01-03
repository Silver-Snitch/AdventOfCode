#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
  string calledNums;
  cin >> calledNums;
  stringstream stream(calledNums);
  vector<int> calledNumbers;
  while (stream.good()) {
    string temp;
    getline(stream, temp, ',');
    calledNumbers.push_back(stoi(temp));
  }
  int l = 0, r = 10000000, answer = r * calledNumbers.size();
  while (l <= r) {
    int p1 = l + (r - l) / 3, p2 = r - (r - l) / 3;
    int fp1 = 0;
    for (auto& itr : calledNumbers) {
      int diff = abs(p1 - itr);
      fp1 += diff * (diff + 1) / 2;
    }
    int fp2 = 0;
    for (auto& itr : calledNumbers) {
      int diff = abs(p2 - itr);
      fp2 += diff * (diff + 1) / 2;
    }
    answer = min({answer, fp1, fp2});
    if (fp1 < fp2)
      r = p2 - 1;
    else
      l = p1 + 1;
  }
  cout << answer << '\n';

  return 0;
}
