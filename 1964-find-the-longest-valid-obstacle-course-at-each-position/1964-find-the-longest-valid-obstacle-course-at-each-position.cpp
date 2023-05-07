class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) 
    {
        int n = obstacles.size();
        vector<int> longestObstacleCourse(n), lis(n);
        int lisLength = 0;
        
        for(int i=0; i<n; i++) 
        {
            int left = 0, right = lisLength;
            while(left < right) 
            {
                int middle = (left + right) >> 1;
                if(lis[middle] <= obstacles[i]) 
                {
                    left = middle + 1;
                }
                else 
                {
                    right = middle;
                }
            }
            
            if(left >= lisLength || lis[left] > obstacles[i]) 
            {
                lis[left] = obstacles[i];
            }
            if(left == lisLength) 
            {
                lisLength++;
            }
            longestObstacleCourse[i] = left + 1;
        }
        return longestObstacleCourse;
    }
};