class Solution {
public:
    int minOperations(vector<string>& logs) 
    {
        int x = 0;
        
        for(auto i:logs)
        {
            if(i.size() == 3 && i[0] == '.' && i[1] == '.' && i[2] == '/')
            {
                x = x > 0 ? x-1 : 0;
            }
            
            else if(i.size() == 2 && i[0] == '.' && i[1] == '/') continue;
            
            else x++;
        }
        return x;
    }
};