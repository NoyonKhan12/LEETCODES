class Solution {
public:
    int dp[101][301][2];
    int helper(vector<int> &piles, int n, int i, int turn, int m)
    {
        if(i >= n) return 0;
        if(dp[i][m][turn] != -1) return dp[i][m][turn];
        
        if(turn == 0)
        {
            int cursum = 0;
            int ans = 0;
            for(int x=0; x<2*m; x++)
            {
                if(i+x < n)
                {
                    cursum += piles[i+x]; 
                    ans = max(ans, cursum+helper(piles, n, i+x+1, 1-turn, max(m, x+1)));
                }
                else break;
            }
            return dp[i][m][turn] = ans;
        }
        else
        {
            int ans = INT_MAX;
            for(int x = 0; x < 2*m; x++)
            {
                if(i+x < n)
                {
                    ans = min(ans, helper(piles, n, i+x+1, 1-turn, max(m, x+1)));
                }
                else break;
            }
            return dp[i][m][turn] = ans;
        }
    }

    int stoneGameII(vector<int>& piles)
    {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        int ans = helper(piles, n, 0, 0, 1);
        return ans;
    }
};