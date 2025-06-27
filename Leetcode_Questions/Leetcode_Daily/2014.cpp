// 2014. Longest Subsequence Repeated k Times

// You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.

// A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

// A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.

// For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".
// Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string.

 

// Example 1:

// example 1
// Input: s = "letsleetcode", k = 2
// Output: "let"
// Explanation: There are two longest subsequences repeated 2 times: "let" and "ete".
// "let" is the lexicographically largest one.
// Example 2:

// Input: s = "bb", k = 2
// Output: "b"
// Explanation: The longest subsequence repeated 2 times is "b".
// Example 3:

// Input: s = "ab", k = 2
// Output: ""
// Explanation: There is no subsequence repeated 2 times. Empty string is returned.
 

// Constraints:

// n == s.length
// 2 <= n, k <= 2000
// 2 <= n < k * 8
// s consists of lowercase English letters.


class Solution {
public:
    // Check if 'target' is a subsequence of 's'
    bool isSubsequence(const string& target, const string& s) {
        int i = 0;
        for (char c : s) {
            if (c == target[i]) i++;
            if (i == target.size()) return true;
        }
        return i == target.size();
    }

    // Check if 'seq' repeated k times is a subsequence of s
    bool canForm(const string& seq, const string& s, int k) {
        string repeated;
        for (int i = 0; i < k; ++i) repeated += seq;
        return isSubsequence(repeated, s);
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        // Build list of characters that appear at least k times
        string chars;
        for (char c = 'z'; c >= 'a'; --c) {
            if (freq[c] >= k) chars += c;
        }

        string best = "";

        // Try sequences of length 1 to 7 (k * len ≤ 2000)
        function<void(string)> dfs = [&](string curr) {
            if ((int)curr.size() > 7) return;

            if (canForm(curr, s, k)) {
                if (curr.size() > best.size() || (curr.size() == best.size() && curr > best))
                    best = curr;
                for (char c : chars) {
                    dfs(curr + c);
                }
            }
        };

        dfs("");

        return best;
    }
};
