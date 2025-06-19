// 768. Max Chunks To Make Sorted II
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array arr.

// We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

// Return the largest number of chunks we can make to sort the array.

 

// Example 1:

// Input: arr = [5,4,3,2,1]
// Output: 1
// Explanation:
// Splitting into two or more chunks will not return the required result.
// For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
// Example 2:

// Input: arr = [2,1,3,4,4]
// Output: 4
// Explanation:
// We can split into two chunks, such as [2, 1], [3, 4, 4].
// However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> left_max(n), right_min(n);
        
        // Compute prefix max
        left_max[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            left_max[i] = max(left_max[i - 1], arr[i]);
        }
        
        // Compute suffix min
        right_min[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right_min[i] = min(right_min[i + 1], arr[i]);
        }
        
        // Count valid splits
        int chunks = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (left_max[i] <= right_min[i + 1]) {
                ++chunks;
            }
        }
        
        // Total chunks = number of valid splits + 1
        return chunks + 1;
    }
};
