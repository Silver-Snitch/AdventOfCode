#include <bits/stdc++.h>
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
  for (auto itr : calledNumbers) cout << itr << ' ';
  cout << '\n';
  map<int, int> transformation;
  for (int i = 0; i < calledNumbers.size(); i++) {
    transformation[calledNumbers[i]] = i + 1;
  }

  function<int(vector<vector<int>>, int)> getScore =
      [&](vector<vector<int>> board, int turns) {
        set<int> marked;
        for (int i = 0; i < turns; i++) marked.insert(calledNumbers[i]);
        int sum = 0;
        for (int i = 0; i < 5; i++) {
          for (int j = 0; j < 5; j++) {
            if (marked.count(board[i][j])) continue;
            sum += board[i][j];
          }
        }
        return sum * calledNumbers[turns - 1];
      };

  int minTurns = calledNumbers.size();
  int maxScore = -1;
  int val;
  while (cin >> val) {
    vector<vector<int>> currentBoard(5, vector<int>(5, val));
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (i + j == 0) continue;
        cin >> currentBoard[i][j];
      }
    }
    int turnsRequired = calledNumbers.size() + 1;
    vector<vector<int>> transformedBoard(5, vector<int>(5));
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        transformedBoard[i][j] = transformation[currentBoard[i][j]];
        if (transformedBoard[i][j] == 0)
          transformedBoard[i][j] = calledNumbers.size() + 1;
      }
    }

    for (int i = 0; i < 5; i++) {
      // for row i to be completely marked out
      int temp = 0;
      for (int j = 0; j < 5; j++) temp = max(temp, transformedBoard[i][j]);
      turnsRequired = min(turnsRequired, temp);
      if (turnsRequired < minTurns) {
        minTurns = turnsRequired;
        maxScore = getScore(currentBoard, turnsRequired);
      }
    }

    for (int j = 0; j < 5; j++) {
      // for column j to be completely marked out
      int temp = 0;
      for (int i = 0; i < 5; i++) temp = max(temp, transformedBoard[i][j]);

      turnsRequired = min(turnsRequired, temp);
      if (turnsRequired < minTurns) {
        minTurns = turnsRequired;
        maxScore = getScore(currentBoard, turnsRequired);
      }
    }
  }
  cout << maxScore << '\n';
  return 0;
}
