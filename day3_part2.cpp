#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  vector<string> input;
  string curr;
  while (cin >> curr) {
    input.push_back(curr);
  }
  string oxygenRating = "", co2Rating = "";
  for (char ch : {'o', 'c'}) {
    int len = input[0].size();
    vector<bool> isActive(input.size(), true);
    int activeCount = input.size();
    int bit = 0;
    while (activeCount > 1) {
      int oneCount = 0, zeroCount = 0;
      for (int i = 0; i < input.size(); i++) {
        oneCount += (isActive[i] && input[i][bit] == '1');
        zeroCount += (isActive[i] && input[i][bit] == '0');
      }
      char turnOff;
      if (ch == 'o')
        turnOff = (oneCount >= zeroCount) ? '0' : '1';
      else
        turnOff = (oneCount >= zeroCount) ? '1' : '0';

      for (int i = 0; i < input.size(); i++) {
        if (!isActive[i]) continue;
        if (input[i][bit] == turnOff) {
          isActive[i] = false;
          activeCount--;
        }
      }
      bit++;
    }
    for (int i = 0; i < input.size(); i++)
      if (isActive[i]) {
        if (ch == 'o')
          oxygenRating = input[i];
        else if (ch == 'c')
          co2Rating = input[i];
      }
  }
  int oxygenRatingInt = 0, co2RatingInt = 0;
  for (char ch : oxygenRating) {
    oxygenRatingInt = oxygenRatingInt * 2 + (ch == '1');
  }
  for (char ch : co2Rating) {
    co2RatingInt = co2RatingInt * 2 + (ch == '1');
  }

  cout << oxygenRatingInt * co2RatingInt << '\n';

  return 0;
}
