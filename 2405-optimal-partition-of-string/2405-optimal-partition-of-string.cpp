class Solution {
public:
    int partitionString(string s) 
    {
        int i = 0, flag = 0;
        int ans = 1;
        
        while(i < s.size())
        {
            int val = s[i] - 'a';
            cout<<val;
            
            if(flag & (1 << val)) 
            {
                flag = 0;
                ans++;
            }
            
            flag = flag | (1 << val);
            i++;
        }
        
        return ans;
    }
};