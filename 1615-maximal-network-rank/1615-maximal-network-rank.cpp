class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads)
    {
        vector<int> adj[n+1];
        
        for(auto x:roads)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        for(auto &x:adj)
        {
            sort(x.begin(), x.end());
        }
        
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int temp_ans = adj[i].size() + adj[j].size();
                int index = lower_bound(adj[i].begin(), adj[i].end(), j) - adj[i].begin();
                
                if(index != adj[i].size())
                {
                    if(adj[i][index] == j)
                    {
                        temp_ans--;
                    }
                }
                ans = max(ans, temp_ans);
            }
        }
        return ans;
    }
};