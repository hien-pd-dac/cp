// Author: hienpdbk
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define ll long long
#define uset unordered_set
#define umap unordered_map

using namespace std;

class Task {
public:
  int N;
  vector<ll> A;
  int Q;
  vector<tuple<int, int, int>> qs;

  void Solve() {
    cin >> N;
    A = vector<ll>(N);
    for (auto i = 0; i < N; i++) {
      cin >> A[i];
    }

    cin >> Q;
    qs = vector<tuple<int, int, int>>(Q);
    for (auto i = 0; i < Q; i++) {
      int type;
      cin >> type;
      if (type == 1) {
        int xq;
        cin >> xq;
        qs[i] = {1, xq, 0};
      } else if (type == 2) {
        int iq, xq;
        cin >> iq >> xq;
        qs[i] = {2, iq, xq};
      } else {
        int iq;
        cin >> iq;
        qs[i] = {3, iq, 0};
      }
    }

    int sIdx = 0, eIdx = 0;
    vector<pair<int, int>> exec; // list of start and end index pair;
    for (auto i = 0; i < Q; i++) {
      auto type = get<0>(qs[i]);
      if (type == 1) {
        sIdx = i;
      } else if (type == 3) {
        eIdx = i;
        exec.push_back({sIdx, eIdx});
        sIdx = eIdx + 1;
      }
    }

    auto execSize = exec.size();
    for (size_t i = 0; i < execSize; i++) {
      auto lsIdx = exec[i].first, leIdx = exec[i].second;
      for (auto i = lsIdx; i <= leIdx; i++) {
        query(qs[i]);
      }
    }
    return;
  }

  void query(tuple<int, int, int> q) {
    auto type = get<0>(q);
    if (type == 1) {
      auto xq = get<1>(q);
      // A = vector<ll>(N, xq);
      A.assign(N, xq);
    } else if (type == 2) {
      auto iq = get<1>(q);
      auto xq = get<2>(q);
      A[iq - 1] += xq;
    } else {
      auto iq = get<1>(q);
      cout << A[iq - 1] << endl;
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
