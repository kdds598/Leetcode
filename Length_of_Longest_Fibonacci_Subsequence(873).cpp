// 873. Length of Longest Fibonacci Subsequence
// link: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/
// The problem requires finding the longest Fibonacci-like subsequence in an array. The key observation is that a Fibonacci sequence follows the property:  
// F(n) = F(n-1) + F(n-2)  
// Thus, if we fix two starting numbers, we can keep checking whether their sum exists in the array, extending the sequence.

//  Approach
// 1. Use a Hash Set: Store all elements in an unordered set for quick lookup.
// 2. Nested Loops for Pairs: Iterate over all pairs (i, j) in the array and treat them as the first two elements of a possible Fibonacci-like sequence.
// 3. Extend the Sequence: Use a while loop to check whether the sum of the last two numbers exists in the set. If it does, extend the sequence.
// 4. Update Maximum Length: Keep track of the longest sequence found.

//  Complexity
// - Time Complexity:  
//   - The outer two loops run in O(n^2).
//   - The while loop runs at most O(n) for each pair.
//   - This results in a worst-case complexity of O(n^2 log M), where M is the maximum number in the array.
  
// - Space Complexity:  
//   - We use an unordered set to store the array elements, requiring $$O(n)$$ space.

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> values(arr.begin(), arr.end());

        int longest = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = arr[i];
                int b = arr[j];
                int fib_len = 2;
                while (values.count(a + b) > 0) {
                    int sum = a + b;
                    a = b;
                    b = sum;
                    fib_len++;
                }
                if (fib_len > 2) {
                    longest = max(longest, fib_len);
                }
            }
        }
        return longest;
    }
};
