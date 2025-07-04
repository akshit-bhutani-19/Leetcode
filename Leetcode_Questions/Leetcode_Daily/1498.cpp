// 1498. Number of Subsequences That Satisfy the Given Sum Condition

// You are given an array of integers nums and an integer target.

// Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

 

// Example 1:

// Input: nums = [3,5,6,7], target = 9
// Output: 4
// Explanation: There are 4 subsequences that satisfy the condition.
// [3] -> Min value + max value <= target (3 + 3 <= 9)
// [3,5] -> (3 + 5 <= 9)
// [3,5,6] -> (3 + 6 <= 9)
// [3,6] -> (3 + 6 <= 9)
// Example 2:

// Input: nums = [3,3,6,8], target = 10
// Output: 6
// Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
// [3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        // Precompute powers of 2
        vector<int> pow2(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i-1] * 2) % MOD;
        }
        
        int left = 0, right = n - 1;
        int res = 0;
        
        while(left <= right) {
            if(nums[left] + nums[right] <= target) {
                res = (res + pow2[right - left]) % MOD;
                left++;
            } else {
                right--;
            }
        }
        
        return res;
    }
};
