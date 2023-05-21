class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&vis, vector<pair<int,int>>&vp, int dx[], int dy[]){
        int m = grid.size();
        int n = grid[0].size();
        vis[row][col] = 1;
        for(int i = 0; i<4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !grid[nrow][ncol])
                vp.push_back({row,col});
            else if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]){
                dfs(nrow, ncol, grid, vis, vp, dx, dy);
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<pair<int,int>>vp1;
        vector<pair<int,int>>vp2;
        int c = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!vis[i][j] && grid[i][j] && !c){
                    c = 1;
                    dfs(i, j, grid, vis, vp1, dx, dy);
                }
                else if(!vis[i][j] && grid[i][j] && c)
                    dfs(i, j, grid, vis, vp2, dx, dy);
            }
        }

        

        int mini = 1e9;
        for(auto it1: vp1){
            for(auto it2: vp2){
                int x = abs(it1.first-it2.first)+abs(it1.second-it2.second)-1;
                mini = min(mini,x);
            }
        }
        return mini;
    }
};