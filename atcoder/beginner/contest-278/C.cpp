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
  int N, Q;
  vector<int> T, A, B;

  void Solve() {
    cin >> N >> Q;
    T = A = B = vector<int>(Q);
    for (auto i = 0; i < Q; i++) {
      cin >> T[i] >> A[i] >> B[i];
    }
    umap<int, uset<int>> status;
    for (auto i = 0; i < Q; i++) {
      if (T[i] == 1) {
        if (!status[A[i]].count(B[i])) {
          status[A[i]].insert(B[i]);
        }
      } else if (T[i] == 2) {
        if (status[A[i]].count(B[i])) {
          status[A[i]].erase(B[i]);
        }
      } else {
        if (status[A[i]].count(B[i]) && status[B[i]].count(A[i])) {
          cout << "Yes" << endl;
        } else {
          cout << "No" << endl;
        }
      }
    }
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
