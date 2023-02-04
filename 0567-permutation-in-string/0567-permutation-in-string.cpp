class Solution 
{
private:
    bool isEqual(vector<int> v1, vector<int> v2)
    {
        for(int i=0; i<26; i++)
        {
            if(v1[i] != v2[i])
            {
                return 0;
            }
        }
        return 1;
    }
    
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
    
        for(int i=0; i<s1.size(); i++)
        {
            int index = s1[i] - 'a';
            v1[index]++;
        }
        
        int i = 0;
        int window = s1.size();
        
        while(i < window && i < s2.size())
        {
            int index = s2[i] - 'a';
            v2[index]++;
            i++;
        }
        
        if(isEqual(v1, v2))
        {
            return 1;
        }
        
        while(i < s2.size())
        {
            int index = s2[i] - 'a';
            v2[index]++;
            
            index = s2[i-window] - 'a';
            v2[index]--;
            
            if(isEqual(v1, v2))
            {
                return 1;
            }
            
            i++;
        }
        return 0;
    }
};