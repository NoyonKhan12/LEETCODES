class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        
        for(int i=n1-1; i>=0; i--)
        {
            for(int j=n2-1; j>=0; j--)
            {
                int c1 = 0, c2 = 0;
                
                if(nums1[i] == nums2[j]) 
                {
                    c1 = 1 + dp[i+1][j+1]; 
                }
                else
                {
                    int l1 = dp[i+1][j];
                    int l2 = dp[i][j+1];
                    c2 = max(l1, l2);
                }
                dp[i][j] = max(c1, c2);
            }
        }
        return dp[0][0];
    }
};