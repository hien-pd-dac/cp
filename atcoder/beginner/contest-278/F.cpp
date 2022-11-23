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
  int n;
  int input;
  int ans = 0;

  void Solve() {
    cin >> n;
    for (auto i = 0; i < n; i++) {
      cin >> input;
    }
    // TODO
    cout << ans << endl;
    return;
  }
};

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  Task t;
  t.Solve();
  return 0;
}
