#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include "../../utils.h"

using namespace std;

// unordered_map works like python dict
vector<int> twoSum(vector<int>& nums, int target) {
    int n = int(nums.size());
    unordered_map<int, int> kindaHashTable;
    for (int i = 0; i < n; ++i) {
        int hashCode = target - nums[i];
        auto searchResult = kindaHashTable.find(hashCode);
        if (searchResult != kindaHashTable.end()) {
            return vector<int>{searchResult->second, i};
        }
        kindaHashTable.emplace(pair(nums[i], i));
    }
    return vector<int>{0, 0};
}

int main() {
    int n, target;
    cin >> n;
    vector<int> nums = readVector<int>(n);
    cin >> target;

    printVector(twoSum(nums, target));
}

/*
 2
 3 3
 6

 4
 2 7 11 15
 9
*/

// IDK how to clamp hash-range in n (with this h-func range is [-1e9, 1e9])
//vector<int> twoSum(vector<int>& nums, int target) {
//    int n = int(nums.size());
//    vector<int> hashTable(n);
//    vector<bool> isInitialized(n, false);
//    for (int i = 0; i < n; ++i) {
//        int hashCode = target - nums[i];
//        if (isInitialized[hashCode]) {
//
//        }
//    }
//}

// IDK how efficiently handle case of same numbers
//vector<int> twoSum(vector<int>& nums, int target) {
//    map<int, int> m;
//    for (int i = 0; i < nums.size(); ++i) {
//        m.emplace(nums[i], i);
//    }
//    for (auto i = m.begin(); i != m.end(); ++i) {
//        int newTarget = target - i->first;
//        auto searchResult = lower_bound(m.begin(), m.end(), newTarget);
//    }
//}