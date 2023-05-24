class Solution {
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b) 
    {
        return a.second > b.second;
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int n = nums1.size();
        vector<pair<int, int>> p;
        
        for(int i=0; i<n; i++) 
        {
            p.push_back({nums1[i], nums2[i]});
        }

        sort(p.begin(), p.end(), comp);

        long long sum = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i=0; i<k; i++) 
        {
            pq.push(p[i]);
            sum += p[i].first;
        }

        long long res = sum * p[k-1].second;
        
        if(n == k) 
        {
            return res;
        }

        for(int i=k; i<n; i++) 
        {
            sum += (p[i].first - pq.top().first);
            pq.pop();
            pq.push(p[i]);
            res = max(res, sum * p[i].second);
        }
        return res;
    }
};