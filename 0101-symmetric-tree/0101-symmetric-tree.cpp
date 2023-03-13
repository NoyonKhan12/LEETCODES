class Solution {
public:
    bool SymTree(TreeNode * r1, TreeNode * r2)
    {    
        if(r1 == NULL && r2 == NULL)
        {
            return true; 
        }		
        else if(r1 == NULL || r2 == NULL || r1->val != r2->val)
        {
            return false;
        }                     
        return SymTree(r1->left, r2->right) && SymTree(r1->right, r2->left);
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        return SymTree(root->left, root->right);     
    }
};