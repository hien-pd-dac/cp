// main.cpp: hienpdbk
// Description: Template used to solve CP.

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

string findID(map<string, unsigned int> idViews) {
    string result;
    unsigned int max = 0;
    for (auto e: idViews) {
        string key = e.first;
        unsigned int val = e.second;
        if (val >= max) {
            max = val;
            result = key;
        }
    }
    return result;
}

vector<vector<string>> solve(map<string, unsigned int> sumViews, map<string, map<string, unsigned int>> allViews, unsigned int maxPop) {
    vector<vector<string>> result;
    for (auto e: sumViews) {
        string name = e.first;
        vector<string> er;
        if (e.second == maxPop) {
            er.push_back(name);
            er.push_back(findID(allViews[name]));
            result.push_back(er);
        }
    }
    return result;
}

vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
    unsigned int maxPop = 0;
    map<string, unsigned int> sumViews;
    map<string, map<string, unsigned int>>  allViews;
    for(auto i = 0; i < int(creators.size()); i++) {
        string name = creators[i];
        string idName = ids[i];
        int view = views[i];
        auto check = allViews.find(name);
        // no-exist creator
        if (check == allViews.end()) {
            allViews[name][idName] = view;
            sumViews[name] = view;
            if (sumViews[name] > maxPop) maxPop = sumViews[name];
            continue;
        }
        // exist creator
        sumViews[name] += view;
        if (sumViews[name] > maxPop) maxPop = sumViews[name];
        auto idCheck = allViews[name].find(idName);
        // no-exist id
        if (idCheck == allViews[name].end()) {
            allViews[name][idName] = view;
            continue;
        }
        // exist id
        allViews[name][idName] += view;
    }
    return solve(sumViews, allViews, maxPop);
}

void show(vector<vector<string>> v) {
    for (auto e: v) {
        for (auto ei: e) {
            cout << ei << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> creators = {"alice","bob","alice","chris"};
    vector<string> ids = {"one","two","three","four"};
    vector<int> views = {5,10,5,4};

    show(mostPopularCreator(creators, ids, views));
    return 0;
}
