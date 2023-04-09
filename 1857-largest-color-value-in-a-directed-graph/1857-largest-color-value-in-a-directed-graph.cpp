class Solution {
public:
    int dfs(int i, string &colors, vector<vector<int>> &al, vector<vector<int>> &cnt, vector<int> &visited) 
    {
        if(!visited[i])
        {
            visited[i] = 1;
            
            for(auto j : al[i]) 
            {
                if(dfs(j, colors, al, cnt, visited) == INT_MAX)   
                {
                    return INT_MAX;
                }
                
                for(auto k=0; k<26; k++)
                {
                    cnt[i][k] = max(cnt[i][k], cnt[j][k]);
                }
            }
            cnt[i][colors[i] - 'a']++;
            visited[i] = 2;
        }
        return visited[i] == 2 ? cnt[i][colors[i] - 'a'] : INT_MAX;
    }
    
    int largestPathValue(string colors, vector<vector<int>>& edges) 
    {
        vector<vector<int>> al(colors.size()), cnt(colors.size(), vector<int>(26));
        vector<int> visited(colors.size());
        
        for(auto &e : edges)
        {
            al[e[0]].push_back(e[1]);
        }
        
        int res = 0;
        
        for(auto i=0; i<colors.size() && res!=INT_MAX; i++)
        {
            res = max(res, dfs(i, colors, al, cnt, visited));
        }
        return res == INT_MAX ? -1 : res;
    }
};