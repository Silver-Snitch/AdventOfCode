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
  vector<int> hash(9,0);
  for(auto& itr:calledNumbers) {
    hash[itr]++;
  }
  for(int i=0;i<256;i++) {
    vector<int> newHash(9,0);
    newHash[6]=hash[0];
    newHash[8]=hash[0];
    for(int i=0;i<8;i++) {
      newHash[i]+=hash[i+1];
    }
    hash=newHash;
  }
  int answer=0;
  for(int i=0;i<9;i++) answer+=hash[i];
  cout<<answer<<'\n';
  return 0;
}
