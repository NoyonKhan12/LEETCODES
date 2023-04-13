class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int i = 0;
        int j = 0;
        
        for(auto value : pushed)
        {
            pushed[i++] = value;
            
            while(i > 0 && pushed[i - 1] == popped[j])
            {
                i--; 
                j++; 
            }
        }
        return i == 0; 
    }
};