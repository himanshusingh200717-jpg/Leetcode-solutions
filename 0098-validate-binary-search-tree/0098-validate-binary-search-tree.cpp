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
bool dfs(TreeNode* root,long low,long high){
    if(root==NULL)return 1;
    if(root->val<=low||root->val>=high)return 0;
    return dfs(root->left,low,root->val)&&dfs(root->right,root->val,high);
    
}
    bool isValidBST(TreeNode* root) {
        return dfs(root,LONG_MIN,LONG_MAX);
        
    }
};