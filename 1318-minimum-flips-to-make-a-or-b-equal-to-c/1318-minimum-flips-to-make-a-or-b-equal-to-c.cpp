class Solution {
public:
    int minFlips(int a, int b, int c) 
    {
        int flips = 0;
        
        while(c > 0 || a > 0 || b > 0)
        {
            if(c % 2 == 1)
            {
                if(a % 2 == 0 && b % 2 == 0)
                {
                    flips++;
                }
            }
            else
            {
                if(a % 2 == 1 && b % 2 == 1)
                {
                    flips = flips + 2;
                }
                else if(a % 2 == 1 || b % 2 == 1)
                {
                    flips++;
                }
            }
            c /= 2;
            a /= 2;
            b /= 2;
        }
        return flips;
    }
};