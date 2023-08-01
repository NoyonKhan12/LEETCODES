class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int x = 0;
        int n = s.size();
        int m = t.size();
        
        for(int i=0; i<m; i++)
        {
            if(s[x] == t[i])
            {
                x++;
            }
        }
        
        return x == n;
    }
};