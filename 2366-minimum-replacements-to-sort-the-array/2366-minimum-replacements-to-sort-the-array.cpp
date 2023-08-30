class Solution {
public:
    long long minimumReplacement(vector<int>& nums) 
    {
        long long counter = 0;
        double next = INT_MAX;
        
        for(int i=nums.size()-1; i>=0; i--)
        {
            if(nums[i] <= next)
            {
                next = nums[i];
                continue;
            }
            
            long long split_element = ceil(nums[i] / next);
            counter += split_element - 1;
            next = nums[i] / split_element;
        }
        return counter;
    }
};