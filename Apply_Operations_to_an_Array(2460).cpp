/*
LeetCode: 2460. Apply Operations to an Array
Link: 2460. Apply Operations to an Array

Explanation:
- If two consecutive elements are equal, double the first one and set the second to 0.
- Shift all non-zero elements to the left while maintaining their relative order.
- Fill the remaining positions with zeros.

Approach:
1. Iterate through the array and modify elements based on given conditions.
2. Count and track the number of zeroes.
3. Shift non-zero elements to the left.
4. Fill the remaining positions with zeros.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int c = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
            if (nums[i] == 0) c++;
        }
        
        int z = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[z++] = nums[i];
            }
        }
        
        while (z < nums.size()) {
            nums[z++] = 0;
        }

        return nums;
    }
};
