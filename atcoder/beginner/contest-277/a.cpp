// Author: hienpdbk
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
  int n, x;
  cin >> n;
  cin >> x;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    arr.push_back(num);
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      cout << ++i;
    };
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();

  return 0;
}
