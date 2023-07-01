class Solution {
public:
    int ans = INT_MAX;
    
    void unfairness(int start, vector<int>& nums, vector<int>& v, int k)
    {
        if(start == nums.size())
        {
            int maxi = INT_MIN;
            for(int i=0; i<k; i++)
            {
                maxi = max(maxi, v[i]);
            }
            ans = min(ans, maxi);
            return;
        }
        
        for(int i=0; i<k; i++)
        {
            v[i] += nums[start];
            
            unfairness(start+1, nums, v, k);
            
            v[i] -= nums[start];
        }
    }
    
    int distributeCookies(vector<int>& nums, int k) 
    { 
        int n = nums.size();
        vector<int> v(k, 0);
        
        unfairness(0, nums, v, k);
        return ans;
    }
};