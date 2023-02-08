class Solution {
public:
    int jump(vector<int>& nums) 
    {
        if(nums.size() == 1)
        {
            return 0;
        }
        
        int maxReach = nums[0];
        int i = 0, k = 0;
        int jump = 1;
        
        while(maxReach < nums.size() - 1)
        {
            jump++;
            
            for(int j=i+1; j<=nums[i]+i; j++)
            {
                if(nums[j] + j > maxReach )
                {
                    maxReach = nums[j] + j;
                    k = j;
                }
            }
            i = k;
        }
        return jump;        
    }
};