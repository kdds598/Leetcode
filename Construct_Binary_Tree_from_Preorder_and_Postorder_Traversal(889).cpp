// 889. Construct Binary Tree from Preorder and Postorder Traversal
// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
// Time Complexity (TC): O(n) → Each node is created once, leading to linear complexity.
// Space Complexity (SC): O(n) → Recursive stack can go up to O(n) in the worst case.
// Recursive Tree Construction Approach

class Solution {
public:
    int pre = 0;  // Tracks the current index in preorder traversal
    int post = 0; // Tracks the current index in postorder traversal

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        // Create a new node with the current preorder value
        TreeNode* curr = new TreeNode(preorder[pre++]);  

        // Recursively build the left subtree if the current node is not at the correct postorder position
        if (curr->val != postorder[post])  
            curr->left = constructFromPrePost(preorder, postorder);

        // Recursively build the right subtree if the current node is still not at the correct postorder position
        if (curr->val != postorder[post])  
            curr->right = constructFromPrePost(preorder, postorder);

        post++; // Move to the next postorder index as this node is now fully processed
        return curr; // Return the constructed subtree
    }
};
