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
  int n, m;
  int input;
  ll ans = 0;

  void solve() {
    cin >> n >> m;

    auto endZeros = countPowOf(n, 10);

    if (endZeros != 0) {
      auto p10OfN = (int)pow(10, endZeros);
      ans = p10OfN * util(n / p10OfN);
    } else {
      ans = util(n);
    }

    cout << ans << endl;
    return;
  }

  // solve when n = x and (x % 10) != 0
  ll util(int x) {
    auto maxK = m;
    if ((x % 2) == 0) {
      auto px = countPowOf(x, 2);
      auto pm = maxPowOf(m, 5);
      auto p = min(px, pm);
      maxK = m / int(pow(5, p));
      auto pMaxK = maxPowOf(maxK, 10);
      return (ll)x * maxDivide(m, pow(10, pMaxK) * pow(5, p));
    } else if ((x % 5) == 0) {
      auto px = countPowOf(x, 5);
      auto pm = maxPowOf(m, 2);
      auto p = min(px, pm);
      maxK = m / int(pow(2, p));
      auto pMaxK = maxPowOf(maxK, 10);
      return (ll)x * maxDivide(m, pow(10, pMaxK) * pow(2, p));
    } else { // (x%10) != 0
      auto p = maxPowOf(m, 10);
      return (ll)x * maxDivide(m, pow(10, p));
    }
  }

  int maxDivide(int x, int d) { return x - x % d; }

  int maxPowOf(int x, int base) {
    if (x < base) {
      return 0;
    }
    return 1 + maxPowOf(x / base, base);
  }

  int countPowOf(int x, int base) {
    int cnt = 0;
    while (x % base == 0) {
      cnt++;
      x = x / base;
    }
    return cnt;
  }
};

int main() {
  // freopen("D.input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.solve();
  }
  return 0;
}
