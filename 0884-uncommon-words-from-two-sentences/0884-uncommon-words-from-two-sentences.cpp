class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        map<string,int> mp;
        vector<string>v;
        string s = "";
        for(int i=0; i<s1.size(); i++)
        {
            if(s1[i]!=' ')
            {
                s = s + s1[i];
            }
            else
            {
                v.push_back(s);
                s.clear();
            }
            if(i==s1.size()-1)
            {
                v.push_back(s);
                s.clear();
            }          
            
        }
        
        for(int i=0; i<s2.size(); i++)
        {
            if(s2[i]!=' ')
            {
                s = s + s2[i];
            }
            else
            {
                v.push_back(s);
                s.clear();
            }
            if(i==s2.size()-1)
            {
                v.push_back(s);
                s.clear();
            }          
            
        }
        
        for(auto i:v)
        {
            mp[i]++;
        }
        vector<string> v2;
        for(auto i:mp)
        {
            if(i.second==1)
            {
                v2.push_back(i.first);
            }
        }
    return v2;
        
    }
};