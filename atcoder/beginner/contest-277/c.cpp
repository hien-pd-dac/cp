// Author: hienpdbk
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>

#define uset unordered_set

using namespace std;

int mmax = 1;
map<int, bool> visited;
void dfs(map<int, uset<int> >& graph, int node) {
    visited[node] = true;
    if (node > mmax) {
        mmax = node;
    }
    for(auto e: graph[node]) {
        if (!visited[e]) {
            dfs(graph, e);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    map<int, uset<int> > graph;
    for(int i = 0; i < n; i++) {
        int first, second;
        cin >> first >> second;
        graph[first].insert(second);
        graph[second].insert(first);
    }
    dfs(graph, 1);
    cout << mmax;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}
