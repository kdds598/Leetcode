// LeetCode Problem: 1092. Shortest Common Supersequence
// Link: https://leetcode.com/problems/shortest-common-supersequence/

/*
# Intuition
- Given two strings, we need to find the shortest string that has both given strings as subsequences.
- This can be achieved by using the Longest Common Subsequence (LCS).
- The idea is to construct the result by merging the characters of both strings while ensuring that the LCS appears only once.

# Approach
1. **Find the LCS of `str1` and `str2`**
   - This helps in identifying the common characters between the two strings.
   - We use Dynamic Programming (DP) to compute the LCS.
2. **Construct the Shortest Common Supersequence (SCS)**
   - Using the LCS, merge both strings while maintaining their relative order.
   - Add all characters from `str1` and `str2` that are not part of LCS.
   - Insert LCS characters in the correct order to ensure minimal length.

# Complexity Analysis
- **Time Complexity**: `O(m * n)` → Finding LCS using DP takes `O(m * n)`, and constructing SCS takes `O(m + n)`.
- **Space Complexity**: `O(m * n)` → DP table storage.

# Code
*/

class Solution {
public:
    // Function to compute the shortest common supersequence
    string shortestCommonSupersequence(string str1, string str2) {
        string ans = "";
        string lcs = findLCS(str1, str2); // Get the longest common subsequence (LCS)

        int p1 = 0, p2 = 0;
        
        // Merge str1 and str2 while ensuring LCS appears only once
        for (char c : lcs) {
            // Add all characters from str1 before the current LCS character
            while (p1 < str1.size() && str1[p1] != c)
                ans += str1[p1++];
            
            // Add all characters from str2 before the current LCS character
            while (p2 < str2.size() && str2[p2] != c)
                ans += str2[p2++];

            // Add the common LCS character
            ans += c;
            ++p1;
            ++p2;
        }

        // Append any remaining characters from str1 and str2
        ans += str1.substr(p1) + str2.substr(p2);
        return ans;
    }

private:
    // Function to compute the Longest Common Subsequence (LCS) of two strings
    string findLCS(string str1, string str2) {
        int len1 = str1.size(), len2 = str2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        // Fill the DP table using bottom-up approach
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1; // Characters match, extend LCS
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Take max of previous states
                }
            }
        }

        // Backtrack to reconstruct the LCS string
        string lcs = "";
        int i = len1, j = len2;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                lcs.push_back(str1[i - 1]); // Add common character
                --i;
                --j;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                --i; // Move upwards in the DP table
            } else {
                --j; // Move left in the DP table
            }
        }

        reverse(lcs.begin(), lcs.end()); // Reverse the LCS to get correct order
        return lcs;
    }
};
