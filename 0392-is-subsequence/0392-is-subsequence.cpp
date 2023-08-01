class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int x = 0;
        int m = s.size();
        int n = t.size();
        
        for(int i=0; i<n; i++)
        {
            if(s[x] == t[i])
            {
                x++;
            }
        }
        
        return x == m;
    }
};