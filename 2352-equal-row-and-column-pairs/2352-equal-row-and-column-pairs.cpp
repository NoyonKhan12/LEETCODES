class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        map<vector<int>, int> mp;
        
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        
        for(auto row:grid)
        {
            mp[row] += 1;
        }
        
        for(int i=0; i<row; i++) 
        {
            vector<int> v;
            
            for(int j=0; j<col; j++) 
            {
                v.push_back(grid[j][i]);
            }
            count += mp[v];
        }
        return count;
        
    }
};