// main.cpp: hienpdbk
// Description: Template used to solve CP.

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int averageValue(vector<int>& nums) {
    int size = 0, sum = 0;
    for (int e: nums) {
        if (e % 6 == 0) {
            sum += e;
            size++;
        }
    }
    if (size == 0) {
        return 0;
    }
    return sum / size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> arr = {1, 3, 6, 10, 12, 15};
    cout << averageValue(arr) << "\n";

    vector<int> arr2 = {1, 2, 4, 7, 10};
    cout << averageValue(arr2) << "\n";
    return 0;
}
