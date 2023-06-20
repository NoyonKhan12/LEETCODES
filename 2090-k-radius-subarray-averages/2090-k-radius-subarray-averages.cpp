class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        int left = 0, right = 0;
        int n = nums.size();
        vector<int> v(n, -1);
        long long sum = 0;
        
        while(right < n)
        {
            sum += nums[right];
            if((right-left+1) == (2*k+1))
            {
                v[right-k] = sum / (2 * k + 1);
                sum -= nums[left];
                left++; 
            }
            right++;
        }
        return v;
    }
};