class Solution {
public:
    
    bool checkRows(vector<vector<int>>& grid, int i, int j)
    {
        int sum = 0, sumRef = 0;
        cout<<"Rows: "<<endl;
        
        for(int a=i; a<i+3; a++)
        {
            for(int b=j; b<j+3; b++)
            {                
                sum = sum + grid[a][b];
            }
            cout<<sum<<endl;
            
            if(a == i)
            {
                sumRef = sum;
                sum = 0;
            }
            else
            {
                if(sum == sumRef)
                {
                    sumRef = sum;
                    sum = 0;
                }
                else
                {
                    return false;
                }
            }
        }
        cout<<endl;
        return true;
    }
    
    bool checkCols(vector<vector<int>>& grid, int i, int j)
    {
        int sum = 0, sumRef = 0;
        cout<<"Columns: "<<endl;
        
        for(int a=j; a<j+3; a++)
        {
            for(int b=i; b<i+3; b++)
            {                
                sum = sum + grid[b][a];
            }
            cout<<sum<<endl;
            
            if(a == j)
            {
                sumRef = sum;
                sum = 0;
            }
            else
            {
                if(sum == sumRef)
                {
                    sumRef = sum;
                    sum = 0;
                }
                else
                {
                    return false;
                }
            }
        }
        cout<<endl;
        return true;
    }
    
    bool checkDiagonals(vector<vector<int>>& grid, int i, int j)
    {
        int n = 3, m = 3;
        int diag1 = 0, diag2 = 0;
        int x = i;
        int y = j;
        
        while(n--)
        {
            diag1 = diag1 + grid[x][y];
            x++;
            y++;
        }
        cout<<"Diagonal 1: "<<diag1<<endl;
        
        x = i;
        y = j + 2;
        
        while(m--)
        {
            diag2 = diag2 + grid[x][y];
            x++;
            y--;
        }
        
        cout<<"Diagonal 2: "<<diag2<<endl;
        cout<<endl;
        return diag1 == diag2;        
    }
    
    bool checkNumbers(vector<vector<int>>& grid, int i, int j)
    {
        vector<int> v(10);
        
        for(int a=i; a<i+3; a++)
        {
            for(int b=j; b<j+3; b++)
            {    
                if(grid[a][b] > 9 || grid[a][b] < 1) return false;
                v[grid[a][b]]++;
                if(v[grid[a][b]] > 1) return false;
            }
        }
        cout<<"Numbers Checked"<<endl;
        return true;
    }
    
    bool checkMagicSquare(vector<vector<int>>& grid, int i, int j)
    {
        if(!checkRows(grid, i, j)) return false;
        if(!checkCols(grid, i, j)) return false;
        if(!checkDiagonals(grid, i, j)) return false;
        if(!checkNumbers(grid, i, j)) return false;
        cout<<endl;
        
        return true;        
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        int sum = 0;
        
        for(int i=0; i<row-2; i++)
        {
            for(int j=0; j<col-2; j++)
            {
                bool x = checkMagicSquare(grid, i, j);
                cout<<x<<endl<<endl;
                sum = sum + (x ? 1 : 0);
            }
        }
        return sum;
    }
};