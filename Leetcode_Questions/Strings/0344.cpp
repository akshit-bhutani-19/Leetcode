// 344. Reverse String

// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

 

// Example 1:

// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]
// Example 2:

// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        char temp;
        for(int i=0;i<(n/2);i++){
            temp = s[i];
            s[i] = s[n-i-1];
            s[n-1-i] = temp;
        }
    }
};