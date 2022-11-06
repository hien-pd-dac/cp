// main.cpp: hienpdbk
// Description: Template used to solve CP.

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<int> applyOperations(vector<int>& nums) {
    vector<int> result;
    int size = nums.size();
    int notZeroCnt  = 0;

    for(int i = 0; i < size ; i++) {
        if (i != (size - 1) && nums[i] == nums[i+1]) {
            nums[i] = nums[i] * 2;
            nums[i+1] = 0;
        }
        if (nums[i] != 0) {
            result.push_back(nums[i]);
            notZeroCnt += 1;
        }
    }

    for(int i = notZeroCnt; i < size; i++) {
        result.push_back(0);
    }
    return  result;
}

void solve() {
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
