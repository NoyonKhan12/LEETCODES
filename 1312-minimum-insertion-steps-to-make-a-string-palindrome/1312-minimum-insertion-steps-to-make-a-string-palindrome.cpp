class Solution {
public:
    int minInsertions(string s)
    {
        int n = s.size();
        vector<int> memo(n, 0);
        int prev, temp;
        
        for(int i=n-2; i>=0; i--)
        {
            prev = 0;    
            
            for(int j=i; j<n; j++)
            {
                temp = memo[j];                              
                memo[j] = s[i] == s[j] ? prev : 1 + min(memo[j], memo[j-1]);   
                prev = temp;
            }
        }
        return memo[s.length()-1];
    }
};