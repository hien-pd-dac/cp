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

void solve() {
    uset<int> first = {'H', 'D', 'C', 'S'};
    uset<int> second = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

    int n;
    cin >> n;
    vector<string> arr;
    for(int i = 0; i < n; i++) {
        string e;
        cin >> e;
        arr.push_back(e);
    }

    set<string> mset;

    for(int i = 0; i < n; i++) {
        if(first.find(arr[i][0]) == first.end()) {
            cout << "No";
            return;
        }
        if(second.find(arr[i][1]) == second.end()) {
            cout << "No";
            return;
        }
        if(mset.find(arr[i]) != mset.end()) {
            cout << "No";
            return;
        }
        mset.insert(arr[i]);
    }
    cout << "Yes";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}
