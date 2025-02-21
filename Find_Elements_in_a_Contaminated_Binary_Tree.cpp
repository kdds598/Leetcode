// 1261. Find Elements in a Contaminated Binary Tree
// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/


/*
Approach:
---------
1. The tree is originally contaminated (values are unknown). We reconstruct it by setting:
   - The root node's value to 0.
   - The left child's value as `2 * parent_val + 1`.
   - The right child's value as `2 * parent_val + 2`.
2. The `makeTree` function recursively updates the tree values following the above rules.
3. The `find` function checks if a given target value exists in the reconstructed tree.

Time Complexity (TC):
----------------------
- `makeTree`: O(N) - We visit each node once to reconstruct the tree.
- `find`: O(N) - In the worst case, we traverse all nodes to find the target.
- Overall: O(N) per operation.

Auxiliary Space Complexity (AC):
--------------------------------
- `makeTree`: O(H) - Due to recursion depth (H = height of the tree).
- `findElem`: O(H) - Due to recursion depth.
- Worst-case space: O(N) (if the tree is skewed).
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class FindElements {
public:
    TreeNode* main = NULL;  // Pointer to store the reconstructed tree's root

    // Constructor to recover the tree
    FindElements(TreeNode* root) {
        if (root) { 
            makeTree(root, 0);  // Start fixing the tree from root with value 0
            main = root;  // Store the fixed tree's root
        }
    }

    // Recursive function to restore the tree values
    void makeTree(TreeNode* root, int d) {
        if (!root) return;  // Base case: If node is null, return

        root->val = d;  // Assign the correct value to the current node

        // Recursively assign values to left and right children
        makeTree(root->left, 2 * d + 1);
        makeTree(root->right, 2 * d + 2);
    }

    // Helper function to search for a target value in the tree
    bool findElem(TreeNode* node, int t) {
        if (!node) return false;  // Base case: If node is null, return false

        if (node->val == t) return true;  // If current node has the target value, return true

        // Recursively search in left and right subtrees
        return findElem(node->left, t) || findElem(node->right, t);
    }

    // Wrapper function to check if the target value exists in the tree
    bool find(int target) {
        return findElem(main, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

