class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<int> v;
        vector<int> visited(n, 0);
        
        int x = edges.size();
        
        for(int i=0; i<x; i++)
        {
            visited[edges[i][1]] = 1;
        }
        
        for(int i=0; i<n; i++)
        {
            if(visited[i] == 0)
            {
                v.push_back(i);
            }
        }
        return v;
    }
};