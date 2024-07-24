class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums)
    {
        vector<int> res;
        multimap<int, int> mp;
        
        for(auto i:nums)
        {
            int num = i;
            string str;
            
            if(i == 0)
            {
                str = to_string(mapping[0]);
            }
            else
            {
                 while(num > 0)
                {
                    int x = num % 10;
                    int y = mapping[x];
                    str = to_string(y) + str;
                    num = num / 10;
                }
            }
           
            int z = stoi(str);
            mp.insert({z, i});
        }
        
        for(auto i:mp)
        {
            res.push_back(i.second);
        }
        
        return res;
    }
};