class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> colors(n, 0);
        queue<int> q;
        
        for(int i=0; i<n; i++) 
        {
            if(colors[i]) 
            {
                continue;
            }
            
            colors[i] = 1;
            q.push(i);
            
            while(q.size() != 0) 
            {
                int front = q.front();
                
                for(auto adjacents : graph[front]) 
                {
                    if(!colors[adjacents])
                    {
                        colors[adjacents] = -1 * colors[front];
                        q.push(adjacents);
                    }
                    else if(colors[adjacents] == colors[front]) 
                    {
                        return false;
                    }
                }
                q.pop();
            }
        }
        return true;
    }
};