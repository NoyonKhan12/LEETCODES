class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        set<int> st;
        int x = edges.size();
        
        for(int i=0; i<x; i++)
        {
            st.insert(edges[i][0]);
            st.insert(edges[i][1]);
        }
        
        for(auto i:edges)
        {
            if(st.find(i[1]) != st.end())
            {
                st.erase(i[1]);
            }
        }
        vector<int> v(st.begin(), st.end());
        return v;
    }
};