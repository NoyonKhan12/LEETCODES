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
    int sum = 0;

    void dfs(TreeNode* root, int low, int high)
    {
        if(!root) return;
        
        dfs(root->left, low, high);
        if(root->val >= low && root->val <= high)
        {
            sum = sum + root->val;
        }
        dfs(root->right, low, high);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        dfs(root, low, high);
        return sum;
    }
};