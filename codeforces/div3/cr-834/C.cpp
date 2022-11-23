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
  int l, r, x;
  int a, b;

  void Solve();
};

void Task::Solve() {
  cin >> l >> r >> x;
  cin >> a >> b;
  if (a == b) {
    cout << 0 << endl;
    return;
  }
  // we can swap (a, b) if a > b without loss of generality.
  // now we have a < b.
  if (a > b) {
    swap(a, b);
  }
  if ((b - a) >= x) {
    cout << 1 << endl; // a -> b
    return;
  }
  if ((b + x) <= r) {
    cout << 2 << endl; // a -> r -> b
    return;
  }
  // when (b+x) > r, we can reach (b+x), so the only way to reach b is through
  // (b-x).
  if ((b - x) < l) {
    cout << -1 << endl; // can not reach (b-x)
    return;
  }
  if ((a - l) >= x) {
    cout << 2 << endl; // a -> l -> b.
    return;
  }
  if ((r - a) < x) {
    cout << -1 << endl; // can not move: a -> r -> (b-x) -> b.
    return;
  }
  cout << 3 << endl; // a -> r -> (b-x) -> b.
  return;
}

int main() {
  // freopen("C.input.txt", "r", stdin);
  // freopen("C.output.txt", "w", stdout);
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
