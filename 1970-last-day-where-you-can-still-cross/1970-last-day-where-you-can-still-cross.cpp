class Solution {
    int row;
    int col;
    vector<vector<int>> cells;
    vector<vector<int>> directions;
    
public:
    Solution() 
    {
        directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) 
    {
        this->row = row;
        this->col = col;
        this->cells = cells;
        
        int left = 1, right = cells.size();
        int mid;
        
        while(left < right) 
        {
            mid = right - (right - left) / 2;
            if(canCross(mid)) 
            {
                left = mid;
            } 
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
    
    bool canCross(int day)
    {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        
        for(int i=0; i<day; i++)
        {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }
        
        for(int i=0; i<col; i++)
        {
            if(grid[0][i] == 0 && dfs(grid, 0, i)) 
            {
                return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<int>>& grid, int r, int c) 
    {
        if(r < 0 || r >= row || c < 0 || c >= col || grid[r][c] != 0) 
        {
            return false;
        }
        
        if(r == row - 1)
        {
            return true;
        }
        grid[r][c] = -1;
        
        for(auto direction : directions) 
        {
            int i = r + direction[0];
            int j = c + direction[1];
            if(dfs(grid, i, j)) 
            {
                return true;
            }
        }
        return false;
    }
};