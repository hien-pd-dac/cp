// Author: hienpdbk
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define uset unordered_set
#define umap unordered_map

using namespace std;

class Task {
public:
  int m, s;
  vector<int> b;
  uset<int> mset;
  string ans;

  void Solve();
  bool isInteger(double a);
};

void Task::Solve() {
  cin >> m >> s;
  b.resize(m);
  ll curSum = 0;
  ans = "YES";
  int curMaxEle = 0;
  for (auto i = 0; i < m; i++) {
    cin >> b[i];
    if (mset.count(b[i])) {
      ans = "NO";
      cout << ans << endl;
      return;
    }
    mset.insert(b[i]);
    curSum += b[i];
    curMaxEle = max(curMaxEle, b[i]);
  }
  ll allSum = curSum + s;
  auto maxEle = sqrt(2 * allSum + (double)1 / 4) - (double)1 / 2;
  if (!isInteger(maxEle)) {
    ans = "NO";
  }
  if (maxEle < curMaxEle) {
    ans = "NO";
  }
  cout << ans << endl;
  return;
}

bool Task::isInteger(double a) {
  int test = a;
  if ((a - test) == 0) {
    return true;
  }
  return false;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Solve();
  }
  return 0;
}
