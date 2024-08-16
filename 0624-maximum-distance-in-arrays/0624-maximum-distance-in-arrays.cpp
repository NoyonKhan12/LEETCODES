class Solution {
public:

    int maxDistance(vector<vector<int>>& arrays)
    {
        int maxDiff = 0;
        int n = arrays.size();
        int x, y;
        int a = arrays[0].size();
        int mini = arrays[0][0];
        int maxi = arrays[0][a-1];

        for(int i=1; i<n; i++)
        {
            a = arrays[i].size();
            
            x = abs(arrays[i][a-1] - mini);
            y = abs(arrays[i][0] - maxi);
            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i][a-1]);
            int c = max(x, y);
            maxDiff = max(maxDiff, c);
            
        }
        return maxDiff;
    }
};