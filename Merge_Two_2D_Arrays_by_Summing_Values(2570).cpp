// LeetCode Problem: 2570. Merge Two 2D Arrays by Summing Values
// Link: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/
// 
// Approach Explanation:
// - Use an unordered_map to store key-value pairs from both arrays.
// - Insert elements from nums1 into the map.
// - Iterate through nums2 and add values to existing keys or insert new keys.
// - Convert the map to a vector and sort it based on keys.
// 
// Time Complexity: O(N log N) (due to sorting, where N is the total unique keys)
// Space Complexity: O(N) (for storing unique key-value pairs in the map)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int, int> m; // Hash map to store merged key-value pairs
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        // Insert elements of nums1 into the map
        for (int i = 0; i < n1; i++) {
            m[nums1[i][0]] = nums1[i][1];
        }
        
        // Add elements of nums2 to the map (if key exists, add values)
        for (int i = 0; i < n2; i++) {
            m[nums2[i][0]] += nums2[i][1];
        }
        
        vector<vector<int>> ans; // Resultant merged array
        
        // Convert hash map to vector
        for (auto& i : m) {
            ans.push_back({i.first, i.second});
        }
        
        // Sort the resultant vector based on keys
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
