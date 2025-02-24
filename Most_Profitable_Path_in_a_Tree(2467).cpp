// LeetCode Problem: 2467. Most Profitable Path in a Tree
// Link: https://leetcode.com/problems/most-profitable-path-in-a-tree/description/

/*
# Intuition
- The problem involves a tree where Alice starts at node 0 and Bob starts at a given node.
- Our goal is to find the maximum profit Alice can collect while considering Bob’s movement.
- Since a tree has a unique path between any two nodes, we can determine Bob’s path and adjust profits accordingly.
- Alice then explores the tree recursively to maximize the total profit.

# Approach
1. Graph Construction
   - Convert the edge list into an adjacency list representation.
2. Finding Bob’s Path
   - There can only be a single Unique path between two nodes in a tree.
   - Use DFS to determine the unique path Bob takes to reach node 0.
   - Store this path and mark affected nodes.
3. Adjusting Node Profits
   - If a node is in the first half of Bob’s path, its profit is set to 0 (Bob reaches first).
   - If a node is exactly at the middle of Bob’s path, its profit is halved (both reach simultaneously).
4. DFS for Maximum Profit
   - Perform a DFS traversal from node 0, calculating the maximum profit Alice can achieve.

# Complexity
- Time Complexity O(n) → We perform DFS twice (once for Bob's path and once for Alice’s profit calculation).
- Space Complexity (O(n) → Storing the adjacency list and recursion stack.

# Code
*/

class Solution {
public:
    // Function to find Bob's path from his starting node to node 0
    bool findBobPath(vector<vector<int>> &adj, vector<int> &curr, vector<int> &bobpath, int start, int parent) {
        if (start == 0) { 
            bobpath = curr; // Store the path Bob takes
            return true;
        }
        curr.push_back(start); // Add current node to the path

        for (auto j : adj[start]) { 
            if (j != parent) { 
                if (findBobPath(adj, curr, bobpath, j, start)) 
                    return true;
            }
        }
        curr.pop_back(); // Backtrack if no path found
        return false;
    }

    // DFS function to calculate the maximum profit Alice can collect
    int dfs(vector<vector<int>> &adj, int start, int parent, vector<int> &amount) {
        int maxi = INT_MIN;

        for (auto nbr : adj[start]) {
            if (nbr != parent) {
                int a = amount[start] + dfs(adj, nbr, start, amount);
                maxi = max(maxi, a);
            }
        }
        
        return maxi == INT_MIN ? amount[start] : maxi; // Return max profit Alice can collect
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n); // Adjacency list representation of the tree

        // Convert edge list to adjacency list
        for (auto &edge : edges) {
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> bobpath, curr;
        findBobPath(adj, curr, bobpath, bob, -1);
        int bl = bobpath.size();

        // Modify profits based on Bob's path
        int i;
        for (i = 0; i < bl / 2; i++) {
            amount[bobpath[i]] = 0; // Bob reaches first, so profit is 0
        }

        if (bl % 2 == 1) {
            amount[bobpath[i]] = 0; // If odd-length path, middle node is set to 0
        } else {
            amount[bobpath[i]] /= 2; // If even-length path, middle node's profit is halved
        }

        return dfs(adj, 0, -1, amount); // Compute max profit Alice can collect
    }
};
