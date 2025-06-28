// 2099. Find Subsequence of Length K With the Largest Sum

// You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

// Return any such subsequence as an integer array of length k.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: nums = [2,1,3,3], k = 2
// Output: [3,3]
// Explanation:
// The subsequence has the largest sum of 3 + 3 = 6.
// Example 2:

// Input: nums = [-1,-2,3,4], k = 3
// Output: [-1,3,4]
// Explanation: 
// The subsequence has the largest sum of -1 + 3 + 4 = 6.

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Store value with index
        vector<pair<int, int>> valWithIndex;
        for (int i = 0; i < n; ++i) {
            valWithIndex.push_back({nums[i], i});
        }
        
        // Step 2: Sort by value in descending order
        sort(valWithIndex.begin(), valWithIndex.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });
        
        // Step 3: Take top k
        vector<pair<int, int>> topK(valWithIndex.begin(), valWithIndex.begin() + k);
        
        // Step 4: Sort the selected k elements by their original index
        sort(topK.begin(), topK.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });
        
        // Step 5: Extract the values
        vector<int> result;
        for (auto &p : topK) {
            result.push_back(p.first);
        }
        
        return result;
    }
};
