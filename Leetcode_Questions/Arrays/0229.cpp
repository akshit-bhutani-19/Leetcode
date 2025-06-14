// 229. Majority Element II

// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: [3]
// Example 2:

// Input: nums = [1]
// Output: [1]
// Example 3:

// Input: nums = [1,2]
// Output: [1,2]

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();

        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Collect elements appearing more than ⌊n/3⌋ times
        vector<int> result;
        for (auto& pair : freq) {
            if (pair.second > n / 3) {
                result.push_back(pair.first);
            }
        }

        return result;
    }
};
