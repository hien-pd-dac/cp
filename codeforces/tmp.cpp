// Author: hienpdbk
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define uset unordered_set
#define umap unordered_map

using namespace std;

class Task {
private:
  // TODO: declare private variables
  int n;
  int input;
  int output;

  // TODO: declare util private methods
  void util();

public:
  Task();
  void Solve();
};

Task::Task() {
  // TODO: init default values, read input
  cin >> n;
  cin >> input;
}

void Task::Solve() {
  util();
  cout << output << endl;
  return;
}

void Task::util() {
  // TODO: util method
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int testCases;
  cin >> testCases;
  while (testCases--) {
    Task t;
    t.Solve();
  }
  return 0;
}
