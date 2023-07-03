class Solution {
public:
    bool buddyStrings(string s, string goal) 
    {
        vector<int> v;

        if(s.size() != goal.size() || s.size() <= 1)
        {
            return false;
        }

        if(s == goal) 
        {
            unordered_set<char> diff(s.begin(), s.end());
            return diff.size() < s.size();
        }

        for(int i=0; i<s.size(); i++) 
        {
            if(s[i] != goal[i]) 
            {
                v.push_back(i);
            }
        }

        if(v.size() != 2) 
        {
            return false;
        }

        swap(s[v[0]], s[v[1]]);
        return s == goal;
    }
};