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
  int n, m;
  map<int, int> cards;
  ll sumOfCards;
  ll minSum;

  void Solve();
};

void Task::Solve() {
  sumOfCards = 0;
  cin >> n >> m;
  for (auto i = 0; i < n; i++) {
    int card;
    cin >> card;
    sumOfCards += card;
    cards[card] += 1;
  }
  int size = int(cards.size());
  if (size == m) {
    cout << 0 << endl;
    return;
  }

  vector<pair<int, int>> vcards;
  for (auto e : cards) {
    vcards.push_back(e);
  }
  cards.clear();

  int startIdx;
  for (auto i = 0; i < size; i++) {
    if (vcards[(i + 1) % size].first != (vcards[i].first + 1) % m) {
      startIdx = i;
      break;
    }
  }
  umap<int, ll> S;
  for (auto i = 0; i < size; i++) {
    int curIdx = (startIdx - i + size) % size;
    int nextIdx = (curIdx + 1 + size) % size, nextCard = vcards[nextIdx].first;
    int curCard = vcards[curIdx].first, num = vcards[curIdx].second;
    if (nextCard != (curCard + 1) % m) {
      S[curCard] = sumOfCards - (ll)curCard * num;
      continue;
    }
    S[curCard] = S[nextCard] - (ll)curCard * num;
  }

  minSum = sumOfCards;
  for (auto e : S) {
    auto card = e.first;
    minSum = min(minSum, S[card]);
  }
  cout << minSum << endl;
  return;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  Task t;
  t.Solve();
  return 0;
}
