// Author: hienpdbk
#include <algorithm>
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
  umap<char, char> nextMap;
  string s;
  string ans;

  void Solve();
};

void Task::Solve() {
  cin >> s;
  nextMap = {{'Y', 'e'}, {'e', 's'}, {'s', 'Y'}};
  auto msize = s.size();
  ans = "YES";
  for (size_t i = 0; i < msize; i++) {
    if (!nextMap.count(s[i])) {
      ans = "NO";
      break;
    }
    if (i + 1 < msize && s[i + 1] != nextMap[s[i]]) {
      ans = "NO";
      break;
    }
  }
  cout << ans << endl;
  return;
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
