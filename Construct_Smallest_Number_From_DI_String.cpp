// 2375. Construct Smallest Number From DI String
// link https://leetcode.com/problems/construct-smallest-number-from-di-string/
//Time Complexity (TC): O(n) → Each number is pushed and popped at most once, leading to linear complexity.
//Space Complexity (SC): O(n) → The stack stores at most n+1 elements in the worst case.
// Stack-based Greedy Approach

class Solution {
public:
    string smallestNumber(string p) {
        int n = p.length();  
        string ans = "";     
        stack<char> s;       
        bool dc = false;  // Flag to check if a 'D' was encountered

        for (int i = 1; i <= n + 1; i++) {
            s.push('0' + i);  // Push current number onto the stack

            // Process when encountering 'I' or at the end
            if (p[i - 1] == 'I') {
                if (!dc) {
                    // If no 'D' encountered before, directly add the number to ans
                    s.pop();
                    ans += ('0' + i);
                } else {
                    // If a 'D' was encountered, empty the stack to maintain decreasing order
                    while (!s.empty()) {
                        ans += s.top();
                        s.pop();
                    }
                    dc = false;  // Reset 'D' encountered flag
                }
            } else {
                dc = true;  // Mark that 'D' was encountered
            }
        }

        // Empty any remaining elements in the stack
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }

        return ans;
    }
};
