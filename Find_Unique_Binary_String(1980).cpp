// 1980. Find Unique Binary String
// leetcode link : https://leetcode.com/problems/find-unique-binary-string/description/

// Explaination

/*
This program finds a binary string of length `n` that is missing from the given list. 
It converts integers to binary strings, ensuring the correct length. 
Using an unordered_set for quick lookups, it iterates through all possible binary numbers 
and returns the first one not present in the input.
*/

class Solution {
public:
    // Converts an integer to a binary string of given 'digits' length
    string int_to_bin(int i, int digits) {
        string a = "";
        while (i) {
            a = (i & 1 ? '1' : '0') + a;
            i >>= 1;
        }
        
        // Pad with leading zeros to match the required digit length
        while (a.length() < digits) {
            a = '0' + a;
        }

        return a;
    }

    // Finds a binary string not present in nums
    string findDifferentBinaryString(vector<string>& nums) {
        int i = nums[0].length();
        int n = (1 << i); // 2^i
        unordered_set<string> m(nums.begin(), nums.end()); // Store existing binary strings

        for (int start = 0; start < n; start++) {
            string a = int_to_bin(start, i); // Ensure length matches the binary digits

            if (m.find(a) == m.end()) {
                return a;
            }
        }

        return "";
    }
};


class Solution {
public:
    // Converts an integer to a binary string of given 'digits' length
    string int_to_bin(int i, int digits) {
        string a = "";
        while (i) {
            a = (i & 1 ? '1' : '0') + a;
            i >>= 1;
        }
        
        // Pad with leading zeros to match the required digit length
        while (a.length() < digits) {
            a = '0' + a;
        }

        return a;
    }

    // Finds a binary string not present in nums
    string findDifferentBinaryString(vector<string>& nums) {
        int i = nums[0].length();
        int n = (1 << i); // 2^i
        unordered_set<string> m(nums.begin(), nums.end()); // Store existing binary strings

        for (int start = 0; start < n; start++) {
            string a = int_to_bin(start, i); // Ensure length matches the binary digits

            if (m.find(a) == m.end()) {
                return a;
            }
        }

        return "";
    }
};
