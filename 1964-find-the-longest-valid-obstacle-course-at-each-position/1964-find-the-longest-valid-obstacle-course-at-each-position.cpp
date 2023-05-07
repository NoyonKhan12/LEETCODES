class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) 
    {
        vector<int> v(obstacles.size()+1, INT_MAX);
        vector<int> ans;

        for(auto it : obstacles)   
        {
            int index = upper_bound(v.begin(), v.end(), it) - v.begin();
            v[index] = it;
            ans.push_back(index+1);
        }
        return ans; 
    }
};