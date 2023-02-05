class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int result = nums.size();
        int x = 0;
        
        for(auto num:nums)
        {
            result = result ^ num;
            result = result ^ x;
            x++;
        }
        return result;
    }
};