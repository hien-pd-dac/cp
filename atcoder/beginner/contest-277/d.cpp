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
  umap<int, int> cards;
  ll sumOfCards;
  ll minSum;

  umap<int, bool> ready;
  umap<int, ll> S;

  void Solve();
  ll Play(int card);
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
  if (cards.size() == size_t(m)) {
    cout << 0 << endl;
    return;
  }
  for (auto e : cards) {
    auto card = e.first;
    Play(card);
  }

  minSum = sumOfCards;
  for (auto e : S) {
    auto card = e.first;
    minSum = min(minSum, S[card]);
  }
  cout << minSum << endl;
  return;
}

ll Task::Play(int card) {
  if (ready[card]) {
    return S[card];
  }
  auto num = cards[card];
  auto next = (card + 1) % m;
  auto remain = sumOfCards;
  if (!cards.count(next)) {
    remain = sumOfCards - (ll)num * card;
  } else {
    remain = Play(next) - (ll)num * card;
  }
  S[card] = remain;
  ready[card] = true;
  return remain;
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
