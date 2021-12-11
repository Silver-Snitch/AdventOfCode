#include <bits/stdc++.h>
using namespace std;

class Point {
 public:
  int x, y;

  Point(int x, int y) : x(x), y(y) {}
};

class Line {
 public:
  Point p1, p2;
  Line(Point p1, Point p2) : p1(p1), p2(p2) {
    if (p1.x > p2.x) swap(this->p1, this->p2);
    if (p1.y > p2.y) swap(this->p1, this->p2);
  }
};

Point readPoint(string str) {
  stringstream stream(str);
  vector<int> calledNumbers;
  while (stream.good()) {
    string temp;
    getline(stream, temp, ',');
    calledNumbers.push_back(stoi(temp));
  }
  return Point(calledNumbers[0], calledNumbers[1]);
}

int32_t main() {
  vector<Line> lines;
  string input;
  while (cin >> input) {
    Point p1 = readPoint(input);
    cin >> input >> input;
    Point p2 = readPoint(input);
    lines.push_back(Line(p1, p2));
  }

  vector<vector<int>> grid(1001, vector<int>(1001, 0));
  for (Line& line : lines) {
    if (line.p1.x != line.p2.x && line.p1.y != line.p2.y) continue;
    for (int i = line.p1.x; i <= line.p2.x; i++) {
      for (int j = line.p1.y; j <= line.p2.y; j++) {
        grid[i][j]++;
      }
    }
  }
  int answer = 0;
  for (auto& itr : grid)
    for (auto& iitr : itr) answer += (iitr > 1);
  cout << answer << '\n';

  return 0;
}
