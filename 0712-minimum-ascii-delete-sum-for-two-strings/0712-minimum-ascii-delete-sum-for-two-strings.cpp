class Solution {
public:
    int solveOpt(string &s1,string &s2)
    {
      int n = s1.length();
      int m = s2.length();
      vector<int> curr(m+1, 0);
      vector<int> next(m+1, 0);
        
      for(int i=n-1; i>=0; i--)
      {
          for(int j=m-1; j>=0; j--)
          {
              int ans = 0;
              if(s1[i] == s2[j])
              {
                  ans = s1[i] + next[j+1];
              }
              else
              {
                  ans = max(next[j], curr[j+1]);
              }
              curr[j] = ans;
          }
          next = curr;
      }
      return next[0];
    }
    
	int minimumDeleteSum(string s1, string s2) 
    {
        int n = s1.length();
        int m = s2.length();
        int sum = 0;
        
        for(int i=0; i<n; i++)
        {
            sum += s1[i];
        }
        
        for(int i=0; i<m; i++)
        {
            sum += s2[i];
        }
        return sum - (2 * (solveOpt(s1, s2)));
    }
};