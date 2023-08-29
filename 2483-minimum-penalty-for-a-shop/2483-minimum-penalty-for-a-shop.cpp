class Solution {
public:
    int bestClosingTime(string customers) 
    {
        int n = customers.size();
        int time;
        
        if(customers[0] == 'Y')
        {
            time = 1;
        }
        else
        {
            time = 0;
        }
        
        int max = time;
        int index = time;
        
        vector<int> v(n, 0);
        v[0] = time;
        
        for(int i=1; i<n; i++)
        {
            if(customers[i] == 'Y')
            {
                time = 1;
            }
            else
            {
                time = 0;
            }
            
            v[i] = v[i-1] + time;
            
            int t = v[i] + v[i];
            int term = t - i - 1;
            
            if(term > max)
            {
                max = term;
                index = i + 1;
            }
        }
        return index;
    }
};