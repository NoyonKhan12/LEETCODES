class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> m;
        
        for(int i=0; i<nums.size(); i++)
        {
            int num = nums[i];
            int comp = target - num;
            auto it = m.find(comp);
            
            if(it != m.end())
            {
                return {(*it).second, i};
            }
            m[num] = i;
        }        
        return {};        
    }
};