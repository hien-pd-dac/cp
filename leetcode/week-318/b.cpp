// main.cpp: hienpdbk
// Description: Template used to solve CP.

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

void insertToMap(map<int, int>& mMap, int key) {
    if (mMap.find(key) == mMap.end()) {
        mMap[key] = 1;
        return;
    }
    mMap[key] += 1;
}

void removeFromMap(map<int, int>& mMap, int key) {
    mMap[key] -= 1;
    if (mMap[key] == 0) {
        mMap.erase(key);
    }
    return;
}

long long maximumSubarraySum(vector<int>& nums, int k) {
    long long maxSum = 0;
    long long curSum = 0;
    int size = nums.size();
    map<int, int> mMap;
    for (int i = 0; i < (k-1); i++) {
        insertToMap(mMap, nums[i]);
        curSum += nums[i];
    }
    for(int i = (k-1); i < size; i++) {
        insertToMap(mMap, nums[i]);
        curSum += nums[i];
        if ((int)mMap.size() != k) {
            removeFromMap(mMap, nums[i-k+1]);
            curSum -= nums[i-k+1];
            continue;
        }
        if (curSum > maxSum) {
            maxSum = curSum;
        }
        removeFromMap(mMap, nums[i-k+1]);
        curSum -= nums[i-k+1];
    }
    return maxSum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // vector<int> input = {1,5,4,2,9,9,9};
    // int k = 3;
    // vector<int> input = {9, 9, 9, 1, 2, 3};
    // int k = 3;
    vector<int> input = {1, 1, 1, 7, 8, 9};
    int k = 3;
    printf("max: %lld\n", maximumSubarraySum(input, k));
    return 0;
}
