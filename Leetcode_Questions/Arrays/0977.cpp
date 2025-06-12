// 977. Squares of a Sorted __ARRAY_OPERATORS
// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

// Example 1:

// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].
// Example 2:

// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        int pos=n;
        int neg;
        for(int i=0;i<n;i++){
            cout << i << endl;
            if (nums[i]>=0){
                pos = i;
                break;
            }
        }
        if (pos>0){
            neg=pos-1;
        }
        for(int j=0; j<n; j++){
            if (neg<0 || (pos<n && nums[pos]<(nums[neg]*(-1)))){
                output[j]=nums[pos]*nums[pos];
                pos++;
            }
            else{
                output[j]=nums[neg]*nums[neg];
                neg--;
            }
        }
        return output;
    }
};