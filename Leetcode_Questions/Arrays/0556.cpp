// 556. Next Greater Element III
// Medium
// Topics
// premium lock icon
// Companies
// Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

// Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

 

// Example 1:

// Input: n = 12
// Output: 21
// Example 2:

// Input: n = 21
// Output: -1

class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        int i = num.length() - 2;

        // Step 1: Find first decreasing digit from the right
        while (i >= 0 && num[i] >= num[i + 1]) {
            i--;
        }

        if (i < 0) return -1; // Entire number is in descending order

        // Step 2: Find the smallest digit greater than num[i] to the right
        int j = num.length() - 1;
        while (num[j] <= num[i]) {
            j--;
        }

        // Step 3: Swap
        swap(num[i], num[j]);

        // Step 4: Reverse the digits after i
        reverse(num.begin() + i + 1, num.end());

        // Step 5: Convert back to integer
        long result = stol(num);
        return (result > INT_MAX) ? -1 : (int)result;
    }
};
