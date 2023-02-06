class Solution {
public:
    vector<int> countBits(int n)
    {
        int cnt;
        vector<int> v;
        char ch = '1';
        
        for(int i=0; i<=n; i++)
        {            
            string str = bitset<32>(i).to_string();
            cnt = count(str.begin(), str.end(), ch);
            v.push_back(cnt);
        }
        return v;        
    }
};