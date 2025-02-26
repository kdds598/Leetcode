// 1749. Maximum Absolute Sum of Any Subarray
// Link: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/
// Running Sum Concept:
// We maintain a running sum (sum) while iterating through the array.
// At each step, we track the maximum (maxi) and minimum (mini) values of the running sum.
// Why This Works:
// The maximum absolute sum of any subarray is achieved when the difference between the highest (maxi) and lowest (mini) running sum values is maximized.
// The result is given by maxi - mini, which ensures we capture both the largest positive and negative subarray sums.
// S.C. O(1)
// T.C. O(n)


class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n= nums.size();
        int maxi=0;
        int mini=0;
        int sum=0;
        for(int i=0;i<n;i++){

            sum+=nums[i];
            maxi=max(maxi,sum);
            mini=min(mini,sum);
          
        }
        return maxi-mini;
    }
};
