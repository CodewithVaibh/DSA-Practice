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
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
            return ans;
        stack<TreeNode*>s1;
        stack<int>s2;
        TreeNode*node=root;
        s1.push(root);
        while(!s1.empty())
        {
            s2.push(s1.top()->val);
            node=s1.top();
            s1.pop();
            if(node->left!=NULL)
                s1.push(node->left);
            if(node->right!=NULL)
                s1.push(node->right);
        }
        while(!s2.empty())
        {
            ans.push_back(s2.top());
            s2.pop();
        }
        return ans;
    }
};