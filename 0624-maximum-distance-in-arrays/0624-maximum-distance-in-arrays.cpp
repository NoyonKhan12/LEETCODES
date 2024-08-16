class Solution {
public:

    int maxDistance(vector<vector<int>>& arrays)
    {
        int n = arrays.size();
        int maxDiff = 0, x, y;
        int a = arrays[0].size() - 1;
        int mini = arrays[0][0];
        int maxi = arrays[0][a];

        for(int i=1; i<n; i++)
        {
            a = arrays[i].size() - 1;
            
            x = abs(arrays[i][a] - mini);
            y = abs(arrays[i][0] - maxi);
            
            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i][a]);
            
            maxDiff = max(maxDiff, max(x, y));
        }
        return maxDiff;
    }
};