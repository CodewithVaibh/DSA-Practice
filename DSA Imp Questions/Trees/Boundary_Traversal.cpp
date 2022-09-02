bool isLeaf(TreeNode<int>*root)
{
    if(root->left==NULL && root->right==NULL)
        return true;
    return false;
}
    

void leftBoundary(TreeNode<int>*root,vector<int>&ans)
{
    TreeNode<int>*cur=root->left;
    while(cur)
    {
        if(!isLeaf(cur))
        ans.push_back(cur->data);
        if(cur->left==NULL)
            cur=cur->right;
        else
            cur=cur->left;
    }
}

void leafnodes(TreeNode<int>*root,vector<int>&ans)
{
    if(isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if(root->left)
        leafnodes(root->left,ans);
    if(root->right)
        leafnodes(root->right,ans);
}


vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>ans;
    if (root==NULL)
        return ans;
    ans.push_back(root->data);
    if(isLeaf(root))
        return ans;
    leftBoundary(root,ans);
    leafnodes(root,ans);
    vector<int>v;
    TreeNode<int>*temp=root->right;
    while(temp)
    {
        if(!isLeaf(temp))
        v.push_back(temp->data);
        if(temp->right==NULL)
            temp=temp->left;
        else
            temp=temp->right;
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        ans.push_back(v[i]);
    }
    return ans;
}