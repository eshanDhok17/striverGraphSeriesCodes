/*
    steps:
    create graph with edge weights
    fill stack by doing toposort
    create distance array and mark source distance as 0
    empty stack and update distances
    return distance array
*/

class Solution {
private:
    void topoSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st) {
        vis[node] = true;
        for(auto &it : adj[node]) {
            int v = it.first;
            if(!vis[v]) {
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
        return ;
    }
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        vector<pair<int, int>>adj[n];
        for(int i=0; i<m; i++) {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        int vis[n] = {0};
        stack<int> st;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        while(!st.empty()) {
            int node=st.top(); st.pop();
            for(auto &it : adj[node]) {
                int v = it.first, wt = it.second;
                if(dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};
