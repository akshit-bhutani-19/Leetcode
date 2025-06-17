// 500. Keyboard Row

// Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

// Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.

// In the American keyboard:

// the first row consists of the characters "qwertyuiop",
// the second row consists of the characters "asdfghjkl", and
// the third row consists of the characters "zxcvbnm".

 

// Example 1:

// Input: words = ["Hello","Alaska","Dad","Peace"]

// Output: ["Alaska","Dad"]

// Explanation:

// Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.



class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // Create a map from characters to row number
        unordered_map<char, int> rowMap;
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        
        for (char c : row1) rowMap[c] = 1;
        for (char c : row2) rowMap[c] = 2;
        for (char c : row3) rowMap[c] = 3;
        
        vector<string> result;
        
        for (string word : words) {
            string lowerWord = word;
            for (char &c : lowerWord) c = tolower(c);
            
            int row = rowMap[lowerWord[0]];
            bool sameRow = true;
            
            for (char c : lowerWord) {
                if (rowMap[c] != row) {
                    sameRow = false;
                    break;
                }
            }
            
            if (sameRow) result.push_back(word);
        }
        
        return result;
    }
};
