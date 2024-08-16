class Solution {
public:

    int maxDistance(vector<vector<int>>& arrays)
    {
        int n = arrays.size();
        int maxDiff = 0, x, y;
        int mini = arrays[0][0];
        int maxi = arrays[0].back();

        for(int i=1; i<n; i++)
        {
            x = abs(arrays[i][0] - maxi);
            y = abs(arrays[i].back() - mini);
            
            maxDiff = max(maxDiff, max(x, y));
            
            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i].back());
        }
        return maxDiff;
    }
};