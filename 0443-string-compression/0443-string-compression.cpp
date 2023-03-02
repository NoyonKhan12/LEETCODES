class Solution {
public:
    int compress(vector<char>& chars)
    {
        int n = chars.size();
        int i = 0, j = 0;
        int newLength = 0;

        while(j < n) 
        {
            while(j < n && chars[i] == chars[j]) 
            {
                j++;
            }
            
            chars[newLength] = chars[i];
            newLength++;
            
            int len = j - i;
            if(len > 1) 
            {
                for(char c: to_string(len)) 
                {
                    chars[newLength] = c;
                    newLength++;
                }
            }
            i = j;
        }
        
        return newLength;     
    }
};