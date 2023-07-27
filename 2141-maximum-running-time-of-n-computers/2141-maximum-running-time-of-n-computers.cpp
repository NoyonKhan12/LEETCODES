class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries)
    {
        long long totalTime = 0; 
        
        for(auto x : batteries) 
        {
            totalTime = totalTime + x; 
        }
        sort(batteries.rbegin(), batteries.rend()); 
        
        for(int i=0; i<batteries.size(); i++, n--) 
        {
            if(batteries[i] <= (totalTime / n)) 
            {
                break;
            }
            totalTime = totalTime - batteries[i]; 
        }
        return totalTime / n;
    }
};