class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int big = INT_MIN;
        int small = INT_MAX;
        
        for(int i=0; i<prices.size(); i++)
        {
            small = min(prices[i], small);
            big = max(prices[i]-small, big);            
        }
        return big;
    }
};