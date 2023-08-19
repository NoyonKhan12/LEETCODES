class DisjointSet {
    public:
    vector<int> size, parent;

    DisjointSet(int n)
    {
        size.resize(n, 1);
        parent.resize(n + 1);
        
        for(int i=0; i<n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if(parent[node] == node)
        {
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v)
        {
            return;
        }

        if(size[ulp_u] >= size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) 
    {  
        vector<vector<int>> edgeCopy;
        
        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            edgeCopy.push_back({wt, u, v, i});
        }
        sort(edgeCopy.begin(), edgeCopy.end());

        
        DisjointSet MST(n);
        int mstWt = 0;
        
        for(auto &it: edgeCopy)
        {
            int wt = it[0];
            int u = it[1];
            int v = it[2];
            
            if(MST.findUPar(u) != MST.findUPar(v))
            {
                mstWt += wt;
                MST.unionBySize(u, v);
            }
        }

        vector<int> criticalEdges;
        vector<int> pseudocritEdges;

        for(int i=0; i<edgeCopy.size(); i++)
        {
            int newMSTwt = 0;
            DisjointSet ds(n);
            int edgeIndex = edgeCopy[i][3];
            
            for(int j=0; j<edgeCopy.size(); j++)
            {
                if(i != j)
                {
                    int wt = edgeCopy[j][0];
                    int u = edgeCopy[j][1];
                    int v = edgeCopy[j][2];
                    
                    if(ds.findUPar(u) != ds.findUPar(v))
                    {
                        newMSTwt += wt;
                        ds.unionBySize(u, v);
                    }
                }
            }
            
            if(newMSTwt > mstWt || ds.size[ds.findUPar(0)] < n) 
            {
                criticalEdges.push_back(edgeIndex);
            }
            else
            {
                int forcedMSTwt = 0;
                DisjointSet forcedDs(n);
                int forcedWt = edgeCopy[i][0];
                int forcedU = edgeCopy[i][1];
                int forcedV = edgeCopy[i][2];
                
                forcedDs.unionBySize(forcedU, forcedV);
                forcedMSTwt += forcedWt;

                for(int j=0; j<edgeCopy.size(); j++)
                {
                    if(i != j)
                    {
                        int wt = edgeCopy[j][0];
                        int u = edgeCopy[j][1];
                        int v = edgeCopy[j][2];
                        
                        if(forcedDs.findUPar(u) != forcedDs.findUPar(v))
                        {
                            forcedMSTwt += wt;
                            forcedDs.unionBySize(u, v);
                        }
                    }
                }
                
                if(forcedMSTwt == mstWt) 
                {
                    pseudocritEdges.push_back(edgeIndex);
                }
            }
        }
        
        vector<vector<int>> res;
        res.push_back(criticalEdges);
        res.push_back(pseudocritEdges);
        
        return res;
    }
};