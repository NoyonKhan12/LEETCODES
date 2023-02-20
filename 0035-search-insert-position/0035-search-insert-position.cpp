class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {     
        auto t = lower_bound(nums.begin(),nums.end(),target);
        return (t - nums.begin());        
    }
};