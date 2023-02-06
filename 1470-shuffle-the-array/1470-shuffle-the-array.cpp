class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) 
    {
        vector<int> s;
        
        for(int i=0, j=n; i<n, j<(2*n); i++, j++)
        {
            s.push_back(nums[i]);
            s.push_back(nums[j]);
        }
        return s;        
    }
};