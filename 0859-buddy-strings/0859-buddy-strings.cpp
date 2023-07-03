class Solution {
public:
    bool buddyStrings(string s, string goal) 
    {
        vector<int> v;
        int n = s.size();
        int m = goal.size();

        if(n != m || n <= 1)
        {
            return false;
        }

        if(s == goal) 
        {
            unordered_set<char> diff(s.begin(), s.end());
            return diff.size() < n;
        }

        for(int i=0; i<n; i++) 
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