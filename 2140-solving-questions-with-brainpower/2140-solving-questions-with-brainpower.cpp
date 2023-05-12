class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        int n = questions.size();
        vector<long long> dp(n, 0ll);
        dp[n-1] = questions[n-1][0];
        
        for(int i=n-2; i>=0; i--)
        {
            int points = questions[i][0];
            int bp = questions[i][1] + 1;
            long long tot_points = points;
            
            if(i+bp < n)
            {
                tot_points += dp[i+bp];
            }
            dp[i] = max(dp[i+1], tot_points);
        }
        return dp[0];
    }
};