class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int i = 0;
        int j = s.size();
 
        for(int k=0; k<t.size(); k++)
        {
            if(s[i] == t[k])
            {
                i++;
            }
        }
        
        return i == j;
    }
};