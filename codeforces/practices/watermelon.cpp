// main.cpp: hienpdbk
// Description: https://codeforces.com/problemset/problem/4/A

#include <iostream>

using namespace std;

bool solve(unsigned short int w) {
    if (w % 2 != 0) {
        return false;
    }
    if (w < 4) {
        return false;
    }
    return true;
}

string convert_to_string(bool b) {
    return b ? "YES" : "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    unsigned short int w;
    cin >> w;
    cout << convert_to_string(solve(w)) << "\n";
    return 0;
}
