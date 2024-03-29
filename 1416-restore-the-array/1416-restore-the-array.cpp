class Solution {
public:
    int numberOfArrays(string s, int k)
    {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[n] = 1; 
        
        for(int i=n-1; i>=0; --i) 
        {
            if(s[i] == '0')
            {
                continue;
            }
            for(long sz=1, n=0; i+sz<=s.size(); ++sz)
            {
                n = n * 10 + s[i + sz - 1] - '0';
                if(n > k)
                {
                    break;
                }
                dp[i] = (dp[i] + dp[i + sz]) % 1000000007;
            }
        }
        return dp[0];     
    }
};