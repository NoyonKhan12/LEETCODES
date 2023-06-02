class Solution {
public:
    void dfs(int &node,vector<vector<int>>&adj,vector<int>&vis,int &ds){
        vis[node]=1;
        ds++;
        for(auto child:adj[node]){
            if(!vis[child]){
                dfs(child,adj,vis,ds);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>>adj(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    int x1=bombs[i][0],y1=bombs[i][1],r1=bombs[i][2];
                    int x2=bombs[j][0],y2=bombs[j][1],r2=bombs[j][2];
                    long long x_2=(long long)(abs(x1-x2))*(long long)(abs(x1-x2));
                    long long y_2=(long long)(abs(y1-y2))*(long long)(abs(y1-y2));
                    long long dist_2=x_2+y_2;
                    long long radii=(long long)(r1)*(long long)(r1);
                    if(dist_2<=radii){
                        adj[i+1].push_back(j+1);
                    }
                }
            }
        }
        vector<int>vis(n+1);
        int maxi=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                int ds=0;
                dfs(i,adj,vis,ds);
                maxi=max(maxi,ds);
                vis.clear();
                vis.resize(n+1);
            }
        }
        return maxi;
    }
};