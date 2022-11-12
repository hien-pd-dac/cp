// Author: hienpdbk
#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

void solve() {
    int n , x;
    cin >> n;
    cin >> x;
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    for(int i = 0; i < n; i++) {
        if(arr[i] == x) {
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
