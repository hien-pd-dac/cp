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
  int N, K;

  void Solve() {
    cin >> N >> K;
    deque<int> A;
    for (auto i = 0; i < N; i++) {
      int a;
      cin >> a;
      A.push_back(a);
    }
    for (auto i = 0; i < K; i++) {
      A.pop_front();
      A.push_back(0);
    }

    for (auto e : A) {
      cout << e << " ";
    }
    cout << endl;

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
