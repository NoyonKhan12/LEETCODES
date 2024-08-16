class Solution {
public:   
    
    
    void tree(Node* root, vector<int>& v)
    {
        if(!root) return;
        
        v.push_back(root->val);
        
        for(auto temp : root->children)
        {
            tree(temp, v);
        }            
    }
    
    vector<int> preorder(Node* root) 
    {
        vector<int> v;

        tree(root, v);
        
        return v;
    }
};