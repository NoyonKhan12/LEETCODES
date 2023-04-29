//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isPlaceable(int n, int k, vector<int> stalls, int mid)
    {
        int leftMost = 0;
        int cowCount = 1;
        
        for(int i=0; i<n; i++)
        {
            if(stalls[i] - stalls[leftMost] >= mid)
            {
                cowCount++;
                leftMost = i;
                if(cowCount == k)
                {
                    return true;
                }
            }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) 
    {
        sort(stalls.begin(), stalls.end());
        
        int start = 0;
        int end = stalls[n-1] - stalls[0] + 1;
        int mid;
        
        while(start < end)
        {
            mid = (start + end + 1) / 2;
            
            if(isPlaceable(n, k, stalls, mid))
            {
                start = mid;
            }
            else
            {
                end = mid - 1;
            }
        }
        return start;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends