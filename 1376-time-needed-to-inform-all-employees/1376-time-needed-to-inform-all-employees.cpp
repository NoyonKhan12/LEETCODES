class Solution {
public:
    int findTime(int i, vector<int>& manager, vector<int>& informTime, vector<int>& timeNeeded)
    {
        if(manager[i] == -1) 
        {
            return 0;
        }

        if(timeNeeded[i] != -1) 
        {
            return timeNeeded[i];
        }

        timeNeeded[i] = informTime[manager[i]] + findTime(manager[i], manager, informTime, timeNeeded);
        return timeNeeded[i];
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        vector<int> timeNeeded(n, -1);
        timeNeeded[headID] = 0;

        for(int i=0; i<n; i++)
        {
            if(timeNeeded[i] == -1)
            {
                findTime(i, manager, informTime, timeNeeded);
            }
        }
        return *max_element(timeNeeded.begin(), timeNeeded.end());
    }
};