/* A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path. */

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
class Solution {
public:
    
  int maxPath(TreeNode*root,int& ans){
        if(root == NULL) 
            return 0;
        int leftSum = max(0, maxPath(root->left, ans));
        int rightSum = max(0, maxPath(root->right, ans));
        ans = max(ans, leftSum + rightSum + root->val);
        return root->val + max(leftSum,rightSum);
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPath(root, ans);
        return ans;
    }
};