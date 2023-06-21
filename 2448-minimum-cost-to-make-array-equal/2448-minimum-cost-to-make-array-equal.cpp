class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) 
    {
        long long l = 1;
        long long r = 1000000;
        long long res = func(nums, cost, 1), x;
        
        while(l < r) 
        {
            x = (l + r) / 2;
            long long y1 = func(nums, cost, x);
            long long y2 = func(nums, cost, x + 1);
            res = min(y1, y2);
            
            if(y1 < y2)
            {
                r = x;
            }
            else
            {
                l = x + 1;
            }
        }
        return res;
    }

    long long func(vector<int>& nums, vector<int>& cost, int x) 
    {
        long long ans = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            ans += 1L * abs(nums[i] - x) * cost[i];
        }
        return ans;
    }
};