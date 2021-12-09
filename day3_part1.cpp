#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  vector<int> oneCount;
  int total = 1;
  string num;
  cin >> num;
  oneCount.assign(num.size(), 0);
  for (int i = 0; num[i]; i++) oneCount[i] += (num[i] == '1');
  while (cin >> num) {
    total++;
    for (int i = 0; num[i]; i++) oneCount[i] += (num[i] == '1');
  }
  int gama = 0;
  for (int i = 0; i < oneCount.size(); i++) {
    gama = gama * 2 + (oneCount[i] > total / 2);
  }
  int epsilon = ((1 << oneCount.size()) - 1) ^ gama;
  cout << gama * epsilon;
  return 0;
}
