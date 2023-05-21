class Solution {
public:
    queue<pair<pair<int, int>, int>> q;
    bool isValid(int i, int j, vector<vector<int>>& grid, vector<vector<bool>> &vis)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid.size() || vis[i][j] || grid[i][j] == 0)
        {
            return false;
        }
        return true;
    }    
    
    void countIsland(int i, int j, vector<vector<int>>& grid, vector<vector<bool>> &vis)
    {
        if(!isValid(i, j, grid, vis))
        {
            return;
        }
        
        vis[i][j] = true;
        
        grid[i][j] = 0;
        
        q.push({{i, j}, 0});
        
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        for(int k=0; k<4; ++k)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            if(isValid(ni, nj, grid, vis))
            {
                countIsland(ni, nj, grid, vis);
            }
        }
        return;
    }

    int shortestBridge(vector<vector<int>>& grid) 
    {
        bool flag = false;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid.size(), false));
        
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid.size(); j++)
            {
                if(grid[i][j] == 1 && !vis[i][j])
                {
                    countIsland(i, j, grid, vis);
                    flag = true;
                    break;
                }       
            }
            if(flag)
            {
                break;
            }
        }
        
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        while(!q.empty())
        { 
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            for(int k=0; k<4; ++k)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid.size() || vis[nx][ny]) 
                {
                    continue;
                }

                if(grid[nx][ny] == 1) 
                {
                    return dis;
                }
                else 
                {
                    vis[nx][ny] = true;
                    q.push({{nx, ny}, dis+1});
                }
            }
        }
        return -1;
    }
};