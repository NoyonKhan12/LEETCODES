vector <int> parent(100005, -1);

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) 
    {
        for(int i=0; i<=n; i++) 
        {
            parent[i] = i;
        }
        
        sort(edges.begin(), edges.end(), [](vector<int>&a, vector<int>&b)
        {
            if(a[2] < b[2]) 
            {
                return true;
            }
            return false;
        });


        for(int i=0; i<queries.size(); i++) 
        {
            queries[i].push_back(i);
        }
			
        sort(queries.begin(), queries.end(), [](vector<int>&a, vector<int>&b)
        {
            if(a[2] < b[2]) 
            {
                return true;
            }
            return false;
        });
        
        vector <bool> ans(queries.size(), false);
        int idx = 0;
        
        for(int i=0; i<queries.size(); i++)
        {
			while(idx < edges.size() and edges[idx][2] < queries[i][2])
            {
                join(edges[idx][0], edges[idx][1]);
                idx++;
            }

            if(find(parent[queries[i][0]]) == find(parent[queries[i][1]])) 
            {
                ans[queries[i][3]] = true;
            }
        }
        return ans;
    }

    int find(int x)
    {
        if(parent[x] == x) 
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void join(int a, int b)
    {
        a = find(a);
        b = find(b);
        
        if(a != b) 
        {
            parent[b] = a;
        }
    }
};
