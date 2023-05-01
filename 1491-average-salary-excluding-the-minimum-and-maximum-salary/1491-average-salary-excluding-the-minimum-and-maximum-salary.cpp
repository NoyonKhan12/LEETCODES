class Solution {
public:
    double average(vector<int>& salary) 
    {
        int n = salary.size();
        
        double max = *max_element(salary.begin(), salary.end());
        double min = *min_element(salary.begin(), salary.end());
        double sum = accumulate(salary.begin(), salary.end(), 0);
        
        double res = sum - max - min;
        double average = res / (n-2);
        
        return average;
    }
};