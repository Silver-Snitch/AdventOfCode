#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  string op;
  int val;
  int x=0, y=0;
  while (cin >> op >> val) {
    if (op == "forward") {
      x += val;
    } else if (op == "down") {
      y += val;
    } else if (op == "up") {
      y -= val;
    } else
      assert(0);
  }
  cout << x * y;

  return 0;
}
