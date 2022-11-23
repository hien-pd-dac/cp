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
  int n;
  vector<int> a;
  string s;

  void Solve();
};

void Task::Solve() {
  cin >> n;
  a.resize(n);
  for (auto i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> s;
  umap<int, char> mark;
  string ans = "YES";
  for (auto i = 0; i < n; i++) {
    if (!mark.count(a[i])) {
      mark[a[i]] = s[i];
    }
    if (mark.count(a[i]) && mark[a[i]] != s[i]) {
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
