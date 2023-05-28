class Solution {
public:
    int minCost(int n, vector<int>& cuts) 
    {
        sort(cuts.begin(), cuts.end());

        vector<int> newCuts;
        newCuts.push_back(0);
        newCuts.insert(newCuts.end(), cuts.begin(), cuts.end());
        newCuts.push_back(n);

        int m = newCuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for(int len=2; len<m; len++) 
        {
            for(int i=0; i<m-len; i++) 
            {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for(int k=i+1; k<j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + newCuts[j] - newCuts[i]);
                }
            }
        }
        return dp[0][m - 1];
    }
};