class Solution {
public:
    
    int modulo = 1e9 + 7;

    int solve(int n, int zero, int one, vector<int> &dp)
    {
        if(n < 0)
        {
            return 0;
        }         
        if(n == 0)
        {
            return 1;
        }                              
        if(dp[n] != -1)
        {
            return dp[n];
        }       
        
        return dp[n] = (solve(n-zero, zero, one, dp) + solve(n-one, zero, one, dp)) % modulo;
    }

    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> dp(high+1, -1);

        int res = 0;

        for(int i=low; i<=high; i++)
        {
            res = (res + solve(i, zero, one, dp)) % modulo;
        }
        return res;
    }
};
