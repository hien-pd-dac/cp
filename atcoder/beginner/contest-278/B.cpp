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
  int H, M;

  void Solve() {
    cin >> H >> M;
    int A = H / 10, C = M / 10;
    int B = H % 10, D = M % 10;
    if (0 <= A && A <= 1) {
      if (B > 5) {
        A = 2, B = 0;
        C = 0, D = 0;
      }
    } else {
      A = 2;
      if (C <= 3 && B <= 3) {
        // do nothing
      } else if (C <= 3 && B > 3) {
        B = 0, A = 0;
        C = 0, D = 0;
      } else if (C > 3 && B <= 3) {
        C = 0, D = 0;
        if (B == 3) {
          B = 0, A = 0;
        } else {
          B = B + 1;
        }
      } else if (C > 3 && B > 3) {
        A = B = C = D = 0;
      }
    }
    cout << A << B << " " << C << D << endl;
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
