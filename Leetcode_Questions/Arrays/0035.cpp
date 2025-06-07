// 35. Search Insert Position
// Given a sorted array of distinct integers and a target value, return the index if the target is found. 
// If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int min = 0;
        int max = nums.size();
        int mid = (min+max)/2;
        while(mid != min && mid != max){
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                min = mid;
            }
            else{
                max = mid;
            }
            mid = (min+max)/2;
        }
        if (target>nums[mid]){
            return mid+1;
        }
        else{
            return mid;
        }
    }
};