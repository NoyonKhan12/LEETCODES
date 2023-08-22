class Solution {
public:
    string convertToTitle(int n) 
    {
        string str = "";
        
        while(n != 0)
        {
            n = n - 1;
            char x = 'A' + (n % 26);
            str = x + str;
            n = n / 26;
        }
        return str;
    }
};