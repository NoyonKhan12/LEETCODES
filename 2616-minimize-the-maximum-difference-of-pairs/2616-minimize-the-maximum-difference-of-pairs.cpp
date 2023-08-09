class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) 
    {
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nums.back() - nums.front();
        
        while(left < right) 
        {
            int mid = left + (right - left) / 2;
            if(pairs(nums, mid, p)) 
            {
                right = mid;
            }
            else 
            {
                left = mid + 1;
            }
        }
        return left;
    }
    
private:
    bool pairs(vector<int>& nums, int mid, int p)
    {
        int count = 0;
        int i = 0;
        
        while(i < nums.size()-1 && count < p)
        {
            if(nums[i+1] - nums[i] <= mid) 
            {
                count++;
                i += 2;
            }
            else 
            {
                i++;
            }
        }
        return count >= p;
    }
};