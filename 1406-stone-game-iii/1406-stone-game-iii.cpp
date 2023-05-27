class Solution {
    
int dp[500001];
    
public:
    int helper(vector<int>&num, int i)
    {
        if(i >= num.size())
        {
             return 0;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        else 
        {
            int ans = INT_MIN;
            ans = max(ans, num[i] - helper(num, i+1)) ;
            
            if(i+1 < num.size())
            {
                ans = max(ans, num[i] + num[i+1] - helper(num, i+2));
            }  
            if(i+2 < num.size())
            {
                ans = max(ans, num[i] + num[i+1] + num[i+2] - helper(num, i+3));
            }
          return dp[i] = ans;
        }
    }
    
    string stoneGameIII(vector<int>&num) 
    {
          for(int i=0; i<num.size(); i++)
          {
              dp[i] = -1;
          }
        
          int res = helper(num, 0);
          if(res > 0)
          {
              return "Alice" ;
          }
          if(res == 0)
          {
              return "Tie";
          }
          return "Bob" ;
    }
};