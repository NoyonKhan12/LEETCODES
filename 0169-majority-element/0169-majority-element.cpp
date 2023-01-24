class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int majorityCount = ((int) nums.size()) / 2;
        unordered_map<int, int> frequency;

        for(auto i : nums)
        {
            if(++frequency[i] > majorityCount)
            {
                return i;
            }
        }   
        return -1;         
    }
};