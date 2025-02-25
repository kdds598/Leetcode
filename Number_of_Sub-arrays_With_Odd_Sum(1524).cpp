// 1524. Number of Sub-arrays With Odd Sum
// Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
// Time Complexity (TC): O(n) → We iterate through the array once, leading to linear complexity.
// Space Complexity (SC): O(1) → Only a few integer variables are used, requiring constant space.
//
// Approach: Prefix Sum and Counting
// - We use the prefix sum technique to track the sum of subarrays ending at each index.
// - Instead of checking all subarrays (which would be O(n^2)), we maintain two counters:
//   1. `oc` (odd count): Number of times the prefix sum has been odd so far.
//   2. `ec` (even count): Number of times the prefix sum has been even so far.
// - Initially, `ec = 1` because an empty prefix sum (0) is even.
// - As we traverse the array:
//   1. If the current prefix sum is odd, it can be paired with all previous even prefix sums to form an odd subarray.  
//      → Increase `count` by `ec` and increment `oc`.
//   2. If the current prefix sum is even, it can be paired with all previous odd prefix sums to form an odd subarray.  
//      → Increase `count` by `oc` and increment `ec`.
// - The result is taken modulo `10^9 + 7` to handle large numbers.

class Solution {
public:
    int mod = 1000000007; // Modulo for large numbers to avoid overflow

    int numOfSubarrays(vector<int>& arr) {
        int count = 0;   // Stores the total number of valid subarrays
        int pSum = 0;    // Stores the prefix sum of the array
        int oc = 0;      // Count of subarrays with an odd sum
        int ec = 1;      // Count of subarrays with an even sum (initialized to 1 to count empty subarrays)

        // Traverse the array and update prefix sum
        for (int i : arr) {
            pSum += i;  

            // If the prefix sum is odd, add the count of even sum subarrays
            if (pSum & 1) { 
                count = (count + ec) % mod;
                oc++;  // Increment odd count
            } 
            // If the prefix sum is even, add the count of odd sum subarrays
            else { 
                count = (count + oc) % mod;
                ec++;  // Increment even count
            }
        }

        return count % mod; // Return the final count modulo 10^9 + 7
    }
};
