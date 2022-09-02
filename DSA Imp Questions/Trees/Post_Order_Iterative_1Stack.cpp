class Solution {
public:
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
            return ans;
        stack<TreeNode*>s;
        TreeNode*temp=root;
        while(!s.empty() || temp!=NULL)
        {
            if(temp!=NULL)
            {
                s.push(temp);
                temp=temp->left;
            }
            else
            {
                TreeNode*node=s.top()->right;
                if(node==NULL)
                {
                    node=s.top();
                    ans.push_back(node->val);
                    s.pop();
                    while(!s.empty() && s.top()->right==node)
                    {
                        node=s.top();
                        s.pop();
                        ans.push_back(node->val);
                    }
                }
                else
                    temp=node;
            }
        }
        return ans;
    }
};