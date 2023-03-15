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
    bool isCompleteTree(TreeNode* root) 
    {
        bool pre = true;
        queue<TreeNode*> node_q;
        node_q.push(root);
        
        while(!node_q.empty())
        {
            TreeNode* node = node_q.front();
            node_q.pop();
            
            if(node == NULL)
            {
                pre = false;
            }
            else
            {
                if(pre == false)
                {               
                    return false;
                }
                node_q.push(node->left);
                node_q.push(node->right);
            }   
        }        
        return true;        
    }
};