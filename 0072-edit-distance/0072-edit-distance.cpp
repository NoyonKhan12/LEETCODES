class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int m = word1.size(), n = word2.size();
        int pre;
        vector<int> curr(n+1, 0);
        
        for(int j=1; j<=n; j++) 
        {
            curr[j] = j;
        }
        for(int i=1; i<=m; i++) 
        {
            pre = curr[0];
            curr[0] = i;
            
            for(int j=1; j<=n; j++) 
            {
                int temp = curr[j];
                
                if(word1[i - 1] == word2[j - 1]) 
                {
                    curr[j] = pre;
                } 
                else 
                {
                    curr[j] = min(pre, min(curr[j - 1], curr[j])) + 1;
                }
                pre = temp;
            }
        }
        return curr[n];        
    }
};