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
  vector<ll> delA;
  deque<int> nonZeroIdxs;
  int lastAssigned = 0;
  int Q;
  vector<tuple<int, int, int>> qs;

  void Solve() {
    cin >> N;
    delA.resize(N);
    for (auto i = 0; i < N; i++) {
      cin >> delA[i];
      nonZeroIdxs.push_back(i);
    }

    cin >> Q;
    qs.resize(Q);
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

    for (int i = 0; i < Q; i++) {
      query(qs[i]);
    }
    return;
  }

  void query(tuple<int, int, int> q) {
    auto type = get<0>(q);
    if (type == 1) {
      auto xq = get<1>(q);
      while (!nonZeroIdxs.empty()) {
        auto idx = nonZeroIdxs.back();
        delA[idx] = 0;
        nonZeroIdxs.pop_back();
      }
      lastAssigned = xq;
    } else if (type == 2) {
      auto iq = get<1>(q);
      auto xq = get<2>(q);
      delA[iq - 1] += xq;
      nonZeroIdxs.push_back(iq - 1);
    } else {
      auto iq = get<1>(q);
      cout << (lastAssigned + delA[iq - 1]) << endl;
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
